/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package producerconsumer;
import java.util.*;

/**
 *
 * @author Towkir
 */
public class ProducerConsumer {
    ArrayList<Integer> list = new ArrayList<>();
    int capacity,i=0,j=0;
    Scanner sc=new Scanner(System.in);

    public ProducerConsumer(int capacity) {
        this.capacity = capacity;
    }
    public void produceItem() throws InterruptedException {
        int itemNumber = 0;
        while (true) {
            synchronized (this) {
                while (list.size() == capacity) {
                    i=0;
                    wait();
                }
                System.out.println("Producer-"+i+":Data to insert in the buffer");
                int x=sc.nextInt();
                System.out.print("Data:"+x);
                System.out.println("\nProducer-"+i+":Data " + x+" is inserted");
                System.out.println("Empty Space:"+(capacity-1));
                System.out.println("Full Space:"+(i+1));
                i++;
                list.add(x);
                notify();
                Thread.sleep(2000);
            }
        }
    }

    public void consumeItem() throws InterruptedException {
        while (true) {
            synchronized (this) {
                while (list.size() == 0) {
                    j=0;
                    wait();
                }
                int item = list.remove(0);
                System.out.println("Consumer-" + j+":consumed data "+item);
                j++;
                notify();
                Thread.sleep(2000);
            }
        }
    }
}
