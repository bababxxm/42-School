# 42 Common Core Portfolio

A centralized monorepo containing all projects developed throughout the **42 Common Core** curriculum.

---

## 📚 Curriculum Overview

| Rank | Projects | Primary Languages / Tech | Description |
| :--- | :--- | :--- | :--- |
| **Rank 00** | [`libft`](./r00/libft) | C | Custom C standard library functions & data structures |
| **Rank 01** | [`Born2beroot`](./r01/Born2beroot) | SysAdmin, Bash | Debian VM configuration, LVM, SSH, UFW, sudo, cron monitoring |
| | [`ft_printf`](./r01/ft_printf) | C | Re-implementation of standard `printf` with format specifiers |
| | [`get_next_line`](./r01/get_next_line) | C | Line-by-line file descriptor reading with buffer management |
| **Rank 02** | [`minitalk`](./r02/minitalk) | C (UNIX Signals) | Client-server IPC using `SIGUSR1` and `SIGUSR2` |
| | [`pipex`](./r02/pipex) | C (UNIX Processes) | UNIX pipeline implementation mimicking `cmd1 \| cmd2` |
| | [`push_swap`](./r02/push_swap) | C (Algorithms) | Stack sorting algorithm optimizing operation counts |
| | [`so_long`](./r02/so_long) | C (MLX42 Graphics) | 2D tile-based top-down graphical game |
| **Rank 03** | [`minishell`](./r03/minishell) | C (Systems Programming) | Functional UNIX shell with parser, pipes, redirections, signals & built-ins |
| | [`philosophers`](./r03/philosophers) | C (POSIX Threads) | Concurrency and multithreading simulation solving the Dining Philosophers problem |
| **Rank 04** | [`cpp00` – `cpp04`](./r04/) | C++98 (OOP) | C++ fundamentals: classes, memory, canonical form, inheritance, polymorphism |
| | [`miniRT`](./r04/miniRT) | C (Graphics & Math) | Basic raytracing engine rendering spheres, planes, cylinders, and lighting |
| | [`NetPractice`](./r04/NetPractice) | Networking | Subnetting, CIDR, IP routing, and network configuration exercises |
| **Rank 05** | [`cpp05` – `cpp09`](./r05/) | C++98 (Advanced) | Exceptions, type casts, templates, STL containers, Ford-Johnson algorithm |
| | [`inception`](./r05/inception) | Docker, SysAdmin | Multi-container infrastructure (NGINX, WordPress, MariaDB) with Docker Compose |
| | [`webserv`](./r05/webserv) | C++98 (Networking) | Non-blocking HTTP/1.1 server with epoll/poll/kqueue, routing, and CGI execution |

---

## 🛠️ Repository Structure

```
common-core/
├── r00/
│   └── libft/                 # Custom C standard library
├── r01/
│   ├── Born2beroot/           # VM setup and monitoring script
│   ├── ft_printf/             # Formatted output printing
│   └── get_next_line/         # Reading lines from file descriptors
├── r02/
│   ├── minitalk/              # Signal-based IPC
│   ├── pipex/                 # UNIX pipes and redirections
│   ├── push_swap/             # Stack sorting algorithm
│   └── so_long/               # 2D game using MLX42
├── r03/
│   ├── minishell/             # UNIX shell
│   └── philosophers/          # Multithreading with mutexes
├── r04/
│   ├── cpp00/ – cpp04/        # C++ Modules (Pointers, OOP, Polymorphism)
│   ├── miniRT/                # Raytracer
│   └── NetPractice/           # Networking and routing practice
└── r05/
    ├── cpp05/ – cpp09/        # C++ Modules (Exceptions, Templates, STL)
    ├── inception/             # Dockerized LEMP infrastructure
    └── webserv/               # Non-blocking HTTP/1.1 web server
```

---

## 🚀 Building & Testing

Each project contains its own `Makefile` adhering to the 42 Norm (providing `all`, `clean`, `fclean`, and `re` rules).

To compile any project:
```bash
cd rXX/<project-name>
make
```

For C++ modules:
```bash
cd r0X/cpp0X/ex0X
make
```

---

## 👤 Author
* **Sorawit Klaokliang** - 42 Bangkok (`sklaokli`) - [GitHub](https://github.com/bababxxm)
