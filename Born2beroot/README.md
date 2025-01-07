# README: Virtualization and Linux Basics

## Table of Contents

1. [What is Virtualization, What is a Virtual Machine, and How Does it Work](#1-what-is-virtualization-what-is-a-virtual-machine-and-how-does-it-work)
2. [The Purpose of Virtual Machines](#2-the-purpose-of-virtual-machines)
3. [The Basic Differences Between Rocky and Debian](#3-the-basic-differences-between-rocky-and-debian)
4. [What is AppArmor, and What's the Difference Between `apt` and `aptitude`](#4-what-is-apparmor-and-whats-the-difference-between-apt-and-aptitude)
5. [What Are Partitions, Their Purpose, and How to Set Them Up](#5-what-are-partitions-their-purpose-and-how-to-set-them-up)
6. [How to View the Partitions of the Machine](#6-how-to-view-the-partitions-of-the-machine)
7. [What Are Primary and Logical Partitions, and What Are Their Differences](#7-what-are-primary-and-logical-partitions-and-what-are-their-differences)
8. [What Is the Difference Between Encrypted Volume and Encrypted Partition](#8-what-is-the-difference-between-encrypted-volume-and-encrypted-partition)
9. [How LVM Works and What It Is All About](#9-how-lvm-works-and-what-it-is-all-about)
10. [What Is Sudo, Why Use It, and How to Set Up Its Strict Rules](#10-what-is-sudo-why-use-it-and-how-to-set-up-its-strict-rules)
11. [How to Create a User and Change Its Password](#11-how-to-create-a-user-and-change-its-password)
12. [How to Create a Group and Assign Users to It](#12-how-to-create-a-group-and-assign-users-to-it)
13. [How to Print the Groups a User Is In](#13-how-to-print-the-groups-a-user-is-in)
14. [How to Change the Hostname of the Machine](#14-how-to-change-the-hostname-of-the-machine)
15. [How to Set Up Strict Password Policy](#15-how-to-set-up-strict-password-policy)
16. [The Basics of Linux Command Line](#16-the-basics-of-linux-command-line)
17. [How to Create and Set Up a Server](#17-how-to-create-and-set-up-a-server)
18. [What Is SSH, How It Works, and How to Set It Up](#18-what-is-ssh-how-it-works-and-how-to-set-it-up)
19. [What Is UFW, How It Works, and How to Set It Up](#19-what-is-ufw-how-it-works-and-how-to-set-it-up)
20. [What Is Cron](#20-what-is-cron)

---

### 1. What is Virtualization, What is a Virtual Machine, and How Does it Work

**Virtualization** is the process of creating virtual versions of hardware devices, operating systems, or storage within a single physical machine. It allows multiple virtual environments to coexist on the same physical hardware, optimizing resource utilization.

A **Virtual Machine (VM)** is a software-based emulation of a physical computer. It includes its own CPU, memory, storage, and network interface. The **hypervisor** manages the allocation of these resources between the host machine (physical hardware) and the guest machines (VMs), ensuring isolation and security.

---

### 2. The Purpose of Virtual Machines

- Running multiple operating systems on one device.
- Testing and developing applications in isolated environments.
- Enhancing security by separating processes from the host machine.
- Optimizing hardware resources and reducing physical server costs.
- Creating backups and replicating environments for disaster recovery.

---

### 3. The Basic Differences Between Rocky and Debian

| Feature             | Rocky Linux                    | Debian                          |
|---------------------|--------------------------------|---------------------------------|
| **Base**            | Red Hat Enterprise Linux (RHEL)| Independent distribution       |
| **Package Manager** | `dnf`/`yum`                   | `apt`/`aptitude`               |
| **Target Audience** | Enterprises needing RHEL stability| General-purpose usage         |
| **Stability**       | Enterprise-grade              | Highly customizable, less focused on enterprises |

---

### 4. What is AppArmor, and What's the Difference Between `apt` and `aptitude`?

- **AppArmor**: A security framework for Linux systems that restricts what actions applications can perform based on pre-defined profiles.  
  - **Enforce Mode**: Blocks restricted actions.
  - **Complain Mode**: Logs restricted actions without blocking them.

- **`apt` vs `aptitude`**:  
  - **`apt`** is a command-line tool for managing packages.
  - **`aptitude`** offers both command-line and graphical interfaces with advanced dependency management.

---

### 5. What Are Partitions, Their Purpose, and How to Set Them Up?

- **Partitions**: Logical divisions of a storage device, each treated as a separate volume.  
  **Purpose**: Organize data, separate OS from user files, and improve system performance.

**Setup**:
1. Use tools like `fdisk` or `parted`.
2. Create a new partition table (e.g., GPT or MBR).
3. Define the size and type of each partition.
4. Format partitions with a filesystem (e.g., ext4).

---

### 6. How to View the Partitions of the Machine?

Run the command:  
```bash
lsblk
```
or  
```bash
fdisk -l
```

---

### 7. What Are Primary and Logical Partitions, and What Are Their Differences?

- **Primary Partition**: A direct storage unit that can boot an OS. Maximum of four on an MBR disk.
- **Logical Partition**: Resides within an extended partition, allowing more than four partitions.

---

### 8. What Is the Difference Between Encrypted Volume and Encrypted Partition?

- **Encrypted Volume**: Encrypts an entire storage volume.
- **Encrypted Partition**: Encrypts a specific partition. More granular control but less flexible.

---

### 9. How LVM Works and What It Is All About?

**Logical Volume Manager (LVM)** provides flexibility for managing storage.  
Components:  
- **Physical Volume (PV)**: Actual storage devices.
- **Volume Group (VG)**: Pool of storage created from PVs.
- **Logical Volume (LV)**: Units carved from VG for filesystems or swap space.

---

### 10. What Is Sudo, Why Use It, and How to Set Up Its Strict Rules?

- **Sudo** allows privileged commands without switching to the root user.  
**Setup strict rules**:  
1. Edit `/etc/sudoers` using `visudo`.
2. Define granular permissions for users or groups.

---

### 11. How to Create a User and Change Its Password?

**Create User**:  
```bash
sudo adduser username
```  
**Change Password**:  
```bash
sudo passwd username
```

---

### 12. How to Create a Group and Assign Users to It?

**Create Group**:  
```bash
sudo groupadd groupname
```  
**Assign Users**:  
```bash
sudo usermod -aG groupname username
```

---

### 13. How to Print the Groups a User Is In?

```bash
groups username
```

---

### 14. How to Change the Hostname of the Machine?

1. Edit `/etc/hostname` and `/etc/hosts`.
2. Run:  
   ```bash
   hostnamectl set-hostname new_hostname
   ```

---

### 15. How to Set Up Strict Password Policy?

1. Edit `/etc/security/pwquality.conf`.
2. Define rules like minimum length, complexity, and retries.

---

### 16. The Basics of Linux Command Line

Common commands:
- `ls`: List files.
- `cd`: Change directory.
- `mkdir`: Create directory.
- `rm`: Remove files.
- `cp`: Copy files.
- `mv`: Move files.
- `man`: Display manual pages.

---

### 17. How to Create and Set Up a Server?

1. Install the desired server software (e.g., Apache, Nginx).  
2. Configure the server using its configuration file (e.g., `/etc/apache2/apache2.conf`).  
3. Start and enable the service:  
   ```bash
   sudo systemctl start apache2
   sudo systemctl enable apache2
   ```

---

### 18. What Is SSH, How It Works, and How to Set It Up?

**SSH** is a secure protocol for remote access to servers. It uses encryption for data transmission.  
**Setup**:
1. Install OpenSSH:  
   ```bash
   sudo apt install openssh-server
   ```
2. Configure `/etc/ssh/sshd_config`.

---

### 19. What Is UFW, How It Works, and How to Set It Up?

**UFW** (Uncomplicated Firewall) manages network access.  
**Setup**:
1. Install UFW:  
   ```bash
   sudo apt install ufw
   ```
2. Allow SSH:  
   ```bash
   sudo ufw allow ssh
   ```
3. Enable UFW:  
   ```bash
   sudo ufw enable
   ```

---

### 20. What Is Cron?

**Cron** is a task scheduler that automates repetitive tasks.  
Example: Schedule a script to run daily:  
```bash
crontab -e
```
Add:  
```bash
0 4 * * * /path/to/script.sh
