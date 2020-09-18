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
public class threadProduce extends Thread{
    private ProducerConsumer producerConsumer;

    public threadProduce(ProducerConsumer producerConsumer) {
        this.producerConsumer = producerConsumer;
    }

    public void run() {
        try {
            producerConsumer.produceItem();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
