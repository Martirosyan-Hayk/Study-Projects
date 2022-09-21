import amqp from 'amqplib/callback_api.js';


amqp.connect('amqp://localhost', function(connectionError, connection) {
    if (connectionError) {
        throw connectionError;
    }
    connection.createChannel(function(channelError, channel) {
        if (channelError) {
            throw channelError;
        }

        const queue = 'publisher';

        channel.assertQueue(queue, {
            durable: false
        });

        console.log("\t Waiting for messages in %s. To exit press CTRL+C", queue);

        channel.consume(queue, function(massage) {
            console.log("\tReceived %s", massage.content.toString());
        }, {
            noAck: true
        });
    });
});