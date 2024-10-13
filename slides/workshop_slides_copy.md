---
theme: default
style: |
  section.lead h1 {
    font-size: 2.5rem;
    text-align: center;
    color: #6699FF;
  }
  section.lead h2 {
    font-size: 2.0rem;
    text-align: center;
    position: absolute;
    top: 2rem;
    left: 2rem;
    right: 2rem;
    color: #6699FF;
  }
    
paginate: false
class: 
    - lead
    - invert
marp: true

---
# ROS Workshop
---

<!-- tell windows users to launch wsl every time they open a new window -->

## Prequisites
- Text editor - VScode (not sponsored)
- Terminal emulator - Depends on your OS
- Docker installation


---


# What is docker?
#

<style scoped>
h1 {
    text-align: center;
    position: unset;
    color: white;
}
</style>

![width:300px center](Docker.png)


<!-- Explain containerization and how it differs from virtualization. -->
---

  - **Containerisation**
    - Think of a container as a lightweight, portable box that contains everything an application needs to run.
    - It includes the application code, runtime, system tools, libraries, and settings.


---

![width:450px center](Docker_origin_meme.webp)

---


# Why docker? 
#
#
- gives you the ability to run a program on any given machine with docker without dependency issues and conflicts
`* additional usecase - scale apps over multiple server`
<!-- Benefits of Docker

Consistency across environments.
Simplified deployment.
Resource efficiency. -->


---

# How does it work?
#


![width:1000px center](docker_file.png)


---

- **Dockerfile**
  - A text file with instructions on how to build a Docker image.
  - It's like a recipe for creating your container environment.
  
- **Docker Image**
  - A snapshot of a container's file system.
  - Built from a Dockerfile.
  - Immutable and can be shared.
  
- **Docker Container**
  - A running instance of a Docker image.
  - Isolated and has its own filesystem, network, and process space.
<!-- add in the explanation with the analogy -->
---

<style scoped>
h2 {
    text-align: center;
    position: unset;
    color: white;
}
</style>


## Basic Docker Commands

---

## Container Management and interaction

  - `docker run`: Create and start a container.
    - Example: `docker run -it --rm f1tenth_gym_ros`
  - `docker ps`: List running containers.
  - `docker exec`: Run commands in a running container.
    - Example: `docker exec -it [container_id] bash`

---


<style>
img[alt~="center"] {
  display: block;
  margin: 0 auto;
}
</style>

# Why *TERMINAL?*
![width:450px center](rm_rf_bslash.jpg)
\* this is basically the `Avada Kedavra` of TERMINAL world, dont ever uses this

<!-- account for differences between different os -->

---
<style scoped>
h2 {
    text-align: center;
    position: unset;
    color: white;
}
</style>

## Basic Terminal Navigation

---

## File Navigation

  - `ls`: List directory contents.
  - `cd`: Change directory.
  `cd /home` - takes you to the home folder
  `cd /` - takes you to the root folder
  - `pwd`: Print working directory path.



---

## File Management

  - `mkdir`: Create new folder.
  `mkdir test_folder`
  - `touch`: Create new empty files.
  - `cp`: Copy files or directories.
  - `mv`: Move or rename files or directories.
  - `rm`: Remove files or directories (use with caution). (rm -rf)

---

## Viewing and Editing Files

  - `cat`: Display file contents.
  - `nano` or `vim`: Basic text editors within the terminal.

---

## Tips and Tricks

  - **Tab Completion**: Quickly complete commands or file names.
  - **Command History**: Use the up/down arrow keys to navigate through previous commands.
  - **Wildcards**: Utilize `*` and `?` for pattern matching.

---

![width:500px center](terminal_meme.webp)

---


 
# Acessing your container through VS code


---

<style scoped>
a {
    text-align: center;
    display: block;
    font-size: .8;
    text-decoration: none;
    margin: 1 auto;
}
</style>
- Explains key concepts (fast!)
[100+ Docker Concepts you Need to Know (youtube.com)](https://www.youtube.com/watch?v=rIrNIzy6U_g)
- CLI Cheat Sheet
[docker_cheatsheet.pdf](https://docs.docker.com/get-started/docker_cheatsheet.pdf)

---

![width:1000px center](docker_vscode1.webp)

---


![width:370px center](docker_vscode2.png)

---

![width:300px center](docker_vscode3.png)

---

![width:450px center](docker_vscode4.png)
