# Cheesebox

A lightweight C++ wrapper around Distrobox for managing Linux containers.

## Overview

Cheesebox provides a simple CLI interface to manage Distrobox containers. It wraps the Distrobox functionality in an easy-to-use command line tool written in C++.

## Features

- Create and manage Distrobox containers
- Start/stop containers
- List all containers
- Export applications from containers
- Export/import containers
- Clone existing containers
- Simple command-line interface

## Prerequisites

- Linux operating system
- Distrobox installed to manage containers
- Podman or Docker installed, but Podman is required for import/export features
- CMake and a C++ compiler

## Building from Source

1. Clone the repository:
   ```bash
   git clone https://github.com/techy-project/Cheesebox.git
   ```

2. Make the build directory and navigate into it:
   ```bash
   mkdir build && cd build
   ```

3. Run CMake to generate the build files:
   ```bash
   cmake ..
   ```

4. And finally, build the project:
   ```bash
   cmake --build .
   ```

5. Optionally, install the Cheesebox binary to your system:
   ```bash
   sudo install cheesebox /usr/bin
   ```

### Without Building

1. Download the latest executable from Cheesebox GitHub Releases.

2. Optionally, install the executabe:
   ```bash
   sudo install cheesebox-* /usr/bin/cheesebox
   ```

## Usage

To see the available commands and their usage, run:
```bash
cheesebox help
```

For more information about a specific command, run:
```bash
cheesebox help <command>
```

## FAQ

### How do I create a container?

Use the `create` command to create a new container. See the help for the `create` command for a list of distros. Usage:

```bash
cheesebox create <name> <distro>
```

### How do I start a container?

Use the `start` command to start a container. Make sure the container has been created first. Usage:

```bash
cheesebox start <name>
```

### How do I stop a container?

Use the `stop` command to stop a container. Usage:

```bash
cheesebox stop <name>
```

### Which programming language is Cheesebox written in?

Cheesebox is written in C++. C++ is a powerful and versatile language that is well-suited for this task due to its performance and ability to interface with low-level system components. And it has more features than C.

### Why is it called Cheesebox?

Cheesebox is named after the cheesebox, a container for cheese. It's a simple and elegant name that is easy to remember and pronounce.

### What is the license?

Cheesebox is licensed under the GPLv3 license. See the [LICENSE](LICENSE) file for details.

### Who made this?

Cheesebox was made by [Techy Project](https://techy-project.github.io). Only one person works on it, and that's **Techy Project**.

### How to use the export feature?

Use the `export` command to export a container. Usage:

```bash
cheesebox export <name> <filename>
```

Example:

```bash
cheesebox export ubuntu ./ubuntu-backup.tar
```

### How to use the import feature?

Use the `import` command to import a container. Usage:

```bash
cheesebox import <filename> <name>
```

Example:

```bash
cheesebox import ./ubuntu-backup.tar ubuntu-backup
```

### How to use the clone feature?

Use the `clone` command to clone an existing container. Usage:

```bash
cheesebox clone <source> <target>
```

Example:

```bash
cheesebox clone ubuntu ubuntu-clone
```

### How to use the export-app feature?

Use the `export-app` command to export an application from a container.

Usage:

```bash
cheesebox export-app <container> <application>
```

Example:

```bash
cheesebox export-app ubuntu firefox
```

Make sure the application is installed in the container before exporting. This feature will export the application to turn into a desktop entry so you can run it from your applications menu.
