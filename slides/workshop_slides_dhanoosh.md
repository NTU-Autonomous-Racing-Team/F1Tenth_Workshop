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
`* additional usecase - scale apps over multiple servers`

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
    - Example: `docker exec -it [container_id/name] bash`

---


<style>
img[alt~="center"] {
  display: block;
  margin: 0 auto;
}
</style>

# Why *TERMINAL?*
![width:450px center](rm_rf_bslash.jpg)
\* this is basically the `Avada Kedavra` of TERMINAL world, dont ever use this

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
  `mkdir folder1`
  - `touch`: Create new empty files.
  `touch file1.txt`  
  `touch file2.txt` 
  - `cp`: Copy files or directories.
`cp file1.txt [to_path]` 
`cp -r folder1 [to_path]` 


---

## File Management

  - `mv`: Move or rename files or directories.
  `mv file2.txt file3.txt`
  `mv file1.txt [to_path]`
  `mv folder1 [to_path]`
  - `rm`: Remove files or directories (use with caution). (rm -rf)
`rm file3.txt`                
`rm -r folder1`               
`rm -rf [path_to_folder]`      

<!-- Deletes file1.txt
Recursively deletes folder1 and all its contents
Forcefully deletes a folder and all its contents without prompting (use with caution) -->

---

## Viewing and Editing Files

  - `cat`: Display file contents.
  `cat file1.txt`
  - `nano` or `vim`: Basic text editors within the terminal.
  `nano file1.txt`

---

## Tips and Tricks

  - **Tab Completion**: Quickly complete commands or file names.
  - **Command History**: Use the up/down arrow keys to navigate through previous commands.
  - **Wildcards**: Utilize `*` and `?` for pattern matching.
  `ls *.txt` Lists all files in the current directory that end with .txt
  `ls file?.txt` Lists files that match the pattern file?.txt, ie:file1.txt

---

![width:500px center](terminal_meme.webp)

---


 
# Acessing your container through VS code


---

![width:1000px center](docker_vscode1.webp)

---


![width:370px center](docker_vscode2.png)

---

![width:300px center](docker_vscode3.png)

---

![width:450px center](docker_vscode4.png)

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
