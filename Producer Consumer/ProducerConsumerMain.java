/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package producerconsumer;
import java.util.Scanner;
/**
 *
 * @author Towkir
 */
public class ProducerConsumerMain {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int n;
        System.out.print("Enter number of Items : ");
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        ProducerConsumer pc = new ProducerConsumer(n);
        threadProduce t1 = new threadProduce(pc);
        threeadConsume t2 = new threeadConsume(pc);
        t1.start();
        t2.start();
    }
    
}
