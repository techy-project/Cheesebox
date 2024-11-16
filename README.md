# About Cheesebox

Cheesebox is a simple Distrobox container manager written in C++.

## Building & Installing

Before building Cheesebox, make sure you have CMake installed.

Make the build directory & cd into it:

```sh
mkdir build && cd build
```

Run CMake to generate the build files:

```sh
cmake ..
```

Build the project:

```sh
make
```

You can now run Cheesebox by typing `./cheesebox` in your terminal. But, if you need that, you can install it to your system.

### Installing

#### `install` method

Use the `install` method to install Cheesebox to your system. Example:

```sh
sudo install cheesebox /usr/bin
```

#### `cp` method

Use the `cp` method to copy the Cheesebox binary to a directory in your PATH. Example:

```sh
sudo cp cheesebox /usr/bin
```

### Uninstalling

To uninstall Cheesebox, you can use the `rm` command. Example:

```sh
sudo rm /usr/bin/cheesebox
```

## Usage

To see the usage of Cheesebox, you can type `cheesebox help` in your terminal.

## License

Cheesebox is licensed under the GPL-3.0 license. See the [LICENSE](LICENSE) file for details.

## FAQ

### What is Distrobox?

Distrobox is a tool to create containers with a variety of Linux distributions.

### What is Cheesebox?

Cheesebox is a Distrobox wrapper written in C++, supposed to be simple and easy to use.

### Is there a GUI version of Cheesebox?

No, there isn't. Use the terminal, it's fun.

### Why is it written in C++?

I like C++. C++ is a powerful language, and it's fun to write.

### Does it use make to build?

Yes, it does. Only if you build it from CMake, as CMake is required to build Cheesebox. It also builds the Makefile.

### Can I use it without a desktop environment?

Yes, you can. Cheesebox doesn't need a desktop environment to work. It is recommended to use it with a desktop environment, though, but not required.

### I thought Cheesebox is a Linux distribution.

No, it's not. Cheesebox is a Distrobox wrapper written in C++.

### Why is it so simple?

Because I don't like bloat. The executable is under 100 KB in size. The source code is under 20 KB in size. This makes Cheesebox a lightweight Distrobox wrapper.

### Why is it so fast?

Because it's written in C++. C++ is a fast language.

### Is it written in Python?

No, it's written in C++. Python is a great language, but it's not as fast as C++.

### What is the first version of Cheesebox?

The first version of Cheesebox is 0.1.1. It was released on 16/11/2024.

### I can't use Distrobox to create containers. When I enter Ubuntu, it is just Fedora.

It is recommended to use Cheesebox instead. Type `cheesebox help create` to see how to create a container with Cheesebox, and there is the support for Ubuntu. You can do this:

```sh
cheesebox create <name> ubuntu:latest
```

This will create a container with the name you want, and it will be based on Ubuntu.

### Is it stable?

Yes, it is. Cheesebox is stable. It is a simple wrapper, so it shouldn't have any issues.

### Just use BoxBuddy, why this?

BoxBuddy is a great GUI Distrobox wrapper. But, I like Cheesebox more. It is simpler, and it is more lightweight. I used to make this because I like C++ more than Python, and I like simple things.

### It should be called Lunchbox.

No, it shouldn't. Cheesebox is a simple Distrobox wrapper. Lunchbox is a stupid name.

### What is the meaning of the name Cheesebox?

Cheesebox is the mix of Cheese and Distrobox. The cheese is metaphorical, as in "cheese" in the sense of "easy", and also a yummy food that is a type of dairy product. Distrobox is the actual name of the tool that Cheesebox wraps, where you can make containers with a variety of "Linux distributions". If we combine together, we get Cheesebox.

### Does it use Docker to create containers?

No, it doesn't. It uses Distrobox to create containers. Distrobox uses Podman or Docker under the hood to create containers and to pull the distribution images.

### Is it a good wrapper?

Yes, it is. It is simple, and it is easy to use. It is a good wrapper for Distrobox.

# Versions

- 0.1.1: The first version of Cheesebox. (Latest)
