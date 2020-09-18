/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package producerconsumer;

/**
 *
 * @author Towkir
 */
public class threeadConsume extends Thread{
    private ProducerConsumer producerConsumer;

    public threeadConsume(ProducerConsumer producerConsumer) {
        this.producerConsumer = producerConsumer;
    }

    public void run() {
        try {
            producerConsumer.consumeItem();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
