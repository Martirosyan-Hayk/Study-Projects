import amqp from 'amqplib/callback_api.js';
import promptSync from 'prompt-sync';
import process from 'process';

const prompt = promptSync();

if(process.argv.length < 3) {
    console.log("\n Usage: node send.js < Time interval to publish massage > \n");
    process.exit(1);
}

let indexOfPublishedMassage = 1;

amqp.connect('amqp://localhost', function (connectionError, connection) {
    if (connectionError) {
        throw connectionError;
    }

    connection.createChannel(function (channelError, channel) {
        if (channelError) {
            throw channelError;
        }

        const queue = 'publisher';
        const message = input();

        setInterval(function () {
            autoPublisher(message, channel, queue);
        }, process.argv[2]);
    });

});

function input() {
    const message = prompt("Enter your message: ");
    return message;
}

function autoPublisher(message, channel, queue) {
    channel.assertQueue(queue, {
        durable: false
    });
    const sendMessage = message + `. <index of message ${indexOfPublishedMassage} >`;
    channel.sendToQueue(queue, Buffer.from(sendMessage));
    console.log("\tSend:  %s", sendMessage);
    ++indexOfPublishedMassage;
}