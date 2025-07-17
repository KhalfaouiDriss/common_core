/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalfaoui47 <khalfaoui47@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:37:40 by khalfaoui47       #+#    #+#             */
/*   Updated: 2025/07/17 03:40:31 by khalfaoui47      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char *command_generator(const char *text, int state)
{
    static int list_index, len;
    char *name;
    static char *commands[] = {
        "chnm", "ls", "cd", "cat", "echo", "exit", "env", "export", "unset", "pwd",
        "mkdir", "rmdir", "touch", "rm", "cp", "mv", "grep", "find", "which",
        "whereis", "locate", "head", "tail", "less", "more", "chmod", "chown",
        "chgrp", "ps", "kill", "killall", "top", "htop", "man", "clear",
        "diff", "tar", "zip", "unzip", "ssh", "scp", "curl", "wget", "nano",
        "vim", "emacs", "df", "du", "mount", "umount", "alias", "history",
        "sudo", "service", "systemctl", "date", "uptime", "whoami", "id",
        "ifconfig", "ping", "traceroute", "netstat", "iptables", "docker",
        "git", "make", "gcc", "g++", "ld", "objdump", "strace", "lsof",
        "tcpdump", "nc", "openssl", "awk", "sed", "cut", "sort", "uniq",
        "tee", "xargs", "basename", "dirname", "test", "expr", "stat",
        "sleep", "time", "yes", "watch", "uptime", "free", "vmstat", "iostat",
        "sar", "lscpu", "lsblk", "lsusb", "lspci", "journalctl", "systemd-analyze",
        "passwd", "groupadd", "useradd", "usermod", "userdel", "groupdel",
        "chroot", "strncpy", "clear", "reset", "tput", "printf",
        "envsubst", "cron", "crontab", "at", "bg", "fg", "jobs", "disown",
        "screen", "tmux", "ssh-keygen", "rsync", "curl", "wget", "git", "svn",
        "hg", "make", "cmake", "meson", "ninja", "ldd", "nm", "objcopy",
        "objdump", "readelf", "strip", "strings", "valgrind", "gdb", "perf",
        "tcpdump", "iptables", "firewalld", "ufw", "systemctl", "journalctl",
        "ip", "ss", "route", "hostname", "nmcli", "bluetoothctl", "rfkill",
        "iwconfig", "iwlist", "nmcli", "ping6", "netcat", "nmap", "who", "w",
        "last", "uptime", "dmesg", "lsattr", "chattr", "getfacl", "setfacl",
        NULL};

    if (!state)
    {
        list_index = 0;
        len = strlen(text);
    }

    while ((name = commands[list_index]))
    {
        list_index++;
        if (strncmp(name, text, len) == 0)
            return strdup(name);
    }
    return NULL;
}

char **my_completion(const char *text, int start, int end)
{
    (void)start;
    (void)end;
    return rl_completion_matches(text, command_generator);
}

static char *get_relative_dir(char *home, char *pwd)
{
    char *relative_path;
    char *dir;

    if (!pwd)
        return NULL;

    if (home && ft_strncmp(home, pwd, ft_strlen(home)) == 0)
    {
        relative_path = pwd + ft_strlen(home);
        if (relative_path[0] == '\0')
            dir = ft_strdup("~");
        else
            dir = ft_strjoin("~", relative_path);
    }
    else
        dir = ft_strdup(pwd);

    return dir;
}

static char *build_prompt_line(t_shell *shell, char *dir, int pwd_exists, char *name)
{
    char *green = "\033[1;32m";
    char *white = "\033[1;32m";
    char *cyan = "\033[1;36m"; 
    char *reset = "\033[0m";   
    char *red = "\033[1;31m";

    char *tmp;

    if (!pwd_exists)
        dir = "?";
    if(!shell->exit_status)
        tmp = ft_strjoin(green, "➜");
    else
        tmp = ft_strjoin(red, "➜");
    tmp = ft_strjoin(tmp, reset);
    tmp = ft_strjoin(tmp, "  ");
    tmp = ft_strjoin(tmp, white);
    tmp = ft_strjoin(tmp, name);
    tmp = ft_strjoin(tmp, reset);
    tmp = ft_strjoin(tmp, " [");
    tmp = ft_strjoin(tmp, cyan);
    tmp = ft_strjoin(tmp, dir);
    tmp = ft_strjoin(tmp, reset);
    tmp = ft_strjoin(tmp, "] ");

    return tmp;
}

char *get_dir(t_shell *shell)
{
    char *home = get_env_value(shell->env, "HOME");
    char *pwd = get_env_value(shell->env, "PWD");
    char *dir;
    char *prompt_line;

    dir = get_relative_dir(home, pwd);

    if (!pwd)
        prompt_line = build_prompt_line(shell, "?", 0, shell->user_name);
    else
        prompt_line = build_prompt_line(shell, dir, 1, shell->user_name);
    return prompt_line;
}
