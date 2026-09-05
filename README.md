# 🌟 42 School — Common Core Journey

<div align="center">

![42 School](https://img.shields.io/badge/42%20Bangkok-sklaokli-000000?style=for-the-badge&logo=42&logoColor=white)
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/C++98-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Docker](https://img.shields.io/badge/Docker-2496ED?style=for-the-badge&logo=docker&logoColor=white)
![Shell](https://img.shields.io/badge/Shell_Script-121011?style=for-the-badge&logo=gnu-bash&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)

[![42 Norminette CI](https://github.com/bababxxm/42-School/actions/workflows/norminette.yml/badge.svg)](https://github.com/bababxxm/42-School/actions/workflows/norminette.yml)

</div>

---

## 📖 About

Welcome! I’m **sklaokli** ([@bababxxm](https://github.com/bababxxm)), a software engineering student at **42 Bangkok**.

**42** is an innovative, tuition-free, peer-driven, and teacher-free coding school. The curriculum centers on deep algorithmic problem-solving, low-level systems programming, operating system primitives, computer graphics, and networking.

This repository serves as a centralized monorepo showcasing my complete **42 Common Core** journey, documenting projects from fundamental C libraries up through complex multi-threaded concurrency, raytracing engines, and an asynchronous HTTP/1.1 web server from scratch.

---

## 🌐 The 42 Ecosystem & Environment

42 School challenges students to become autonomous problem-solvers through strict constraints, peer reviews, and automated verification:

### 📝 Norminette (The Coding Standard)

Almost every C project must strictly adhere to the **Norm** (enforced by `norminette`). This ensures code readability, modular design, and industry-grade standards:

- **25 lines maximum** per function (excluding curly braces).
- **80 columns maximum** per line.
- **4 parameters maximum** per function.
- **5 variable declarations maximum** per function (declared at top of block).
- **Strict prohibition** of `for`, `do...while`, `switch`, `case`, `goto`, and ternary operators.
- **No inline assignment** on variable declaration (unless `static` or `const`).
- Mandatory standard 42 file headers and prototypes.

### 🤖 Moulinette (Automated Evaluator)

**Moulinette** is 42's rigorous automated grading engine. Submissions undergo intensive testing:

- **Norm validation** ✅
- **Functional accuracy** against hidden test suites and edge cases 🛠️
- **Strict memory safety**: Zero memory leaks and zero invalid reads/writes (checked via Valgrind / AddressSanitizer) 💾
- **Crash resistance**: Immediate grade 0 if segmentation fault, bus error, or double-free occurs.

### 👥 Peer Evaluations & The Blackhole

- **Peer Defense**: Every project is defended in person before 2 to 3 peer evaluators who review code line-by-line, run edge-case tests, and verify conceptual comprehension.
- **Grades**: Scored from 0 to 125 (including bonus features).
- **The Blackhole**: A survival countdown timer. Passing projects awards days to keep your Blackhole counter positive.

---

## 📚 Curriculum Overview

| Rank        | Projects                               | Primary Languages / Tech | Description                                                                       |
| :---------- | :------------------------------------- | :----------------------- | :-------------------------------------------------------------------------------- |
| **Rank 00** | [`libft`](./r00/libft)                 | C                        | Custom C standard library functions & data structures                             |
| **Rank 01** | [`Born2beroot`](./r01/Born2beroot)     | SysAdmin, Bash           | Debian VM configuration, LVM, SSH, UFW, sudo, cron monitoring                     |
|             | [`ft_printf`](./r01/ft_printf)         | C                        | Re-implementation of standard `printf` with format specifiers                     |
|             | [`get_next_line`](./r01/get_next_line) | C                        | Line-by-line file descriptor reading with buffer management                       |
| **Rank 02** | [`minitalk`](./r02/minitalk)           | C (UNIX Signals)         | Client-server IPC using `SIGUSR1` and `SIGUSR2`                                   |
|             | [`pipex`](./r02/pipex)                 | C (UNIX Processes)       | UNIX pipeline implementation mimicking `cmd1 \| cmd2`                             |
|             | [`push_swap`](./r02/push_swap)         | C (Algorithms)           | Stack sorting algorithm optimizing operation counts                               |
|             | [`so_long`](./r02/so_long)             | C (MLX42 Graphics)       | 2D tile-based top-down graphical game                                             |
| **Rank 03** | [`minishell`](./r03/minishell)         | C (Systems Programming)  | Functional UNIX shell with parser, pipes, redirections, signals & built-ins       |
|             | [`philosophers`](./r03/philosophers)   | C (POSIX Threads)        | Concurrency and multithreading simulation solving the Dining Philosophers problem |
| **Rank 04** | [`cpp00` – `cpp04`](./r04/)            | C++98 (OOP)              | C++ fundamentals: classes, memory, canonical form, inheritance, polymorphism      |
|             | [`miniRT`](./r04/miniRT)               | C (Graphics & Math)      | Basic raytracing engine rendering spheres, planes, cylinders, and lighting        |
|             | [`NetPractice`](./r04/NetPractice)     | Networking               | Subnetting, CIDR, IP routing, and network configuration exercises                 |
| **Rank 05** | [`cpp05` – `cpp09`](./r05/)            | C++98 (Advanced)         | Exceptions, type casts, templates, STL containers, Ford-Johnson algorithm         |
|             | [`inception`](./r05/inception)         | Docker, SysAdmin         | Multi-container infrastructure (NGINX, WordPress, MariaDB) with Docker Compose    |
|             | [`webserv`](./r05/webserv)             | C++98 (Networking)       | Non-blocking HTTP/1.1 server with epoll/poll/kqueue, routing, and CGI execution   |

---

## 🗂️ Repository Architecture

```
42-School/
├── r00/
│   └── libft/                 # Custom libc & data structures
├── r01/
│   ├── Born2beroot/           # VM setup documentation & monitoring script
│   ├── ft_printf/             # Reimplementation of printf
│   └── get_next_line/         # Reading lines from file descriptors
├── r02/
│   ├── minitalk/              # Signal-based IPC client-server
│   ├── pipex/                 # UNIX pipelines and redirection
│   ├── push_swap/             # Stack sorting algorithm (trials & optimization)
│   └── so_long/               # 2D game using MLX42
├── r03/
│   ├── minishell/             # Custom UNIX shell implementation
│   └── philosophers/          # Multithreading concurrency simulation
├── r04/
│   ├── cpp00/ – cpp04/        # C++ Object-Oriented Programming modules
│   ├── miniRT/                # Raytracer rendering 3D geometric shapes
│   └── NetPractice/           # Network configuration exercises
└── r05/
    ├── cpp05/ – cpp09/        # Advanced C++ (Exceptions, Templates, STL)
    ├── inception/             # Docker Compose LEMP infrastructure
    └── webserv/               # Asynchronous HTTP/1.1 web server
```

---

## 🛠️ Compilation & Usage

All projects provide standard Makefiles with required targets: `all`, `clean`, `fclean`, `re`.

### Compiling a C Project

```bash
cd r02/so_long
make
./so_long maps/map.ber
```

### Compiling a C++ Exercise

```bash
cd r04/cpp00/ex00
make
./megaphone "shhhhh... I think the students are asleep..."
```

### Running Norminette

To verify Norm compliance across C source files:

```bash
norminette r00/libft/
```

---

## 👤 Author

- **Sorawit Klaokliang** (`sklaokli`)
- Student at **42 Bangkok**
- GitHub: [@bababxxm](https://github.com/bababxxm)
