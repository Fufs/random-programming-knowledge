# SSH
Configure SSH authentication using Yubikeys PIV module.

## Getting started

### Configure PINs
[https://developers.yubico.com/PIV/Guides/Device_setup.html](https://developers.yubico.com/PIV/Guides/Device_setup.html)

#### Using Yubico Authenticator
  1. Open Yubico Authenticator and insert your key
  2. From the left sidebar navigate to "Certificates"
  3. From the right sidebar, under "Manage":
    * Change PIV PIN (6-8 digits)
    * Change PIV PUK (6-8 digits; make sure it's extra secure as it's used to reset your PIN)
    * Generate a new PIV management key and protect it with a PIN. I used AES256 to generate mine.
  4. If going to be using resident keys (a key stored on the yubikey that can be installed on a system with a single comamnd), on the left sidebar navigate to "Passkeys", and from the right sidebar change your FIDO2 PIN (4-63 digits)

#### Using YubiKey Manager
As of writing the deb one is broken, use AppImage
  1. Open YubiKey Manager and insert your key
  2. Navigate to Applications > PIV and click on "Configure PINs"
  3. From the screen:
    * Change PIV PIN (6-8 digits). If this is your first time, check "Use default".
    * Change PIV PUK (6-8 digits; make sure it's extra secure as it's used to reset your PIN). If this is your first time, check "Use default".
    * Generate a new PIV management key and protect it with a PIN. I used AES256 to generate mine.
  4. If going to be using resident keys (a key stored on the yubikey that can be installed on a system with a single comamnd), navigate to Applications > FIDO2 and click on "Change PIN" (must be 4-63 digits).

## Github FIDO2 SSH keys
### Sources:
* [https://www.yubico.com/blog/github-now-supports-ssh-security-keys/](https://www.yubico.com/blog/github-now-supports-ssh-security-keys/)
* [https://developers.yubico.com/SSH/Securing_SSH_with_FIDO2.html](https://developers.yubico.com/SSH/Securing_SSH_with_FIDO2.html)

### Steps:
To enable SSH authentication with Github:
  1. Generate a new certificate-key pair<br />

```bash
$ ssh-keygen -t ed25519-sk -O resident -O application=ssh:Github
```
  * `ssh-keygen` - the ssh-keygen executable (using PATH)
  * `-t ed25519-sk` - encryption algorithm, you can also use `ecdsa-sk`
  * `-O resident` - make the key resident (no need to manually import the private key handle on each system)
  * ~~`-O verify-required` - require the PIN to authenticate with the key~~ (check the note below!)
  * `-O application=ssh:Github` - label for the key on your Yubikey. The key will be visible under "Passkeys" (FIDO2). Can be ommited but the default is "ssh:" and is not changeable.

  It will ask for your PIN. This is the FIDO2 PIN you have set up.

  **NOTE: When using Ubuntu and its provided ssh-agent, `-O verify-required` is not working as of writing of this post ([Can't authenticate SSH via `ssh-add -K` for resident FIDO2 key : r/yubikey](https://www.reddit.com/r/yubikey/comments/13p3voq/cant_authenticate_ssh_via_sshadd_k_for_resident/)). Skip that option for now. Your key can still be protected with a passphrase.**

  2. Go to [SSH and GPG keys](https://github.com/settings/keys) section in Github settings. Next to SSH keys click "New SSH key", give it a name, set to authorization, and paste the contents of the public key (from the 2 files that have been generated it's the one with .pub suffix)

  3. On each system you want to be able to authenticate with github add the key handle with one of the following comamnds:

```bash
$ ssh-add -K
```
  to temporarily add the key to the system or

```bash
$ ssh-keygen -K
```
  to add it permanently

  4. Test your credentials with the ssh-client

```bash
$ ssh -T git@github.com
Hi Fufs! You've successfully authenticated, but GitHub does not provide shell access.
```
