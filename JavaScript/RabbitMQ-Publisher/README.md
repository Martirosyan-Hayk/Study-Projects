# RabbitMQ-Publisher

RabbitMQ for Node.js
This is a simple guide to RabbitMQ patterns in MacOS using Node.js.  The steps on this guide may also be applied to other operating systems but be aware that installation and running of RabbitMQ binaries and services could be different. In a nutshell, this guide covers installation, execution and basic configuration of the RabbitMQ service in Node.js.

# Contents
## Getting Started
  1. [Install RabbitMQ](https://www.rabbitmq.com/install-homebrew.html)
  2. [Mac OS Brew install issues](https://docs.brew.sh/Common-Issues)
  3. Start RabbitMQ Service
```bash
brew services start rabbitmq
```

## Dependencies
  1. Install amqplib for using amqp 
  ```bash
  brew install amqplib
  ```
  2. Install prompt-sync for using console input and output
  ```bash
  brew install prompt-sync
  ```
        
## How to run code?
  1. The first run reciev.js
  ```bash
  node src/receive.js
  ```
  2. Next run send.js
  ```bash
  node src/send.js ' Time interval ' ex. 1000
  ```
  3. input the massage in sender 
