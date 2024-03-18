import java.util.Scanner;
public class Exercicio_3_1{
    public static void main(String[] args){

        Scanner sc = new Scanner (System.in);

        int vetor[] = new int[6];
        System.out.println("<< Listando um vetor >>");
        System.out.print("Entre com o valor 1: ");
        vetor[0] = sc.nextInt();
        System.out.print("Entre com o valor 2: ");
        vetor[1] = sc.nextInt();
        System.out.print("Entre com o valor 3: ");
        vetor[2] = sc.nextInt();
        System.out.print("Entre com o valor 4: ");
        vetor[3] = sc.nextInt();
        System.out.print("Entre com o valor 5: ");
        vetor[4] = sc.nextInt();
        System.out.print("Entre com o valor 6: ");
        vetor[5] = sc.nextInt();

        System.out.println("Os valores lidos são: "+ vetor[0] + vetor[1] + vetor[2] + vetor[3] + vetor[4] + vetor[5]);
    }
}