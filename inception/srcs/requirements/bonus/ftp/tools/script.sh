#!/bin/bash

# Secure chroot dir
mkdir -p /var/run/vsftpd/empty

# vsftpd config
cat << EOF > /etc/vsftpd.conf
    listen=YES
    anonymous_enable=NO
    local_enable=YES
    write_enable=YES
    chroot_local_user=YES
    allow_writeable_chroot=YES
    secure_chroot_dir=/var/run/vsftpd/empty
    pasv_enable=YES
    pasv_min_port=21100
    pasv_max_port=21110
    pasv_address=127.0.0.1
EOF

# FTP user
useradd -m -d /home/${FTP_USER} "${FTP_USER}"

echo "${FTP_USER}:${FTP_PASS}" | chpasswd

# FTP directories
mkdir -p /home/${FTP_USER}/ftp/files

chown -R ${FTP_USER}:${FTP_USER} /home/${FTP_USER}/ftp

chmod -R 755 /home/${FTP_USER}/ftp


exec vsftpd /etc/vsftpd.conf
