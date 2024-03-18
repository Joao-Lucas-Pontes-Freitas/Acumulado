import java.util.Scanner;
public class Exercicio_3_3{
    public static void main(String[] args){

        Scanner sc = new Scanner (System.in);

        int vetor[] = new int[6];

        System.out.println("<< Listando um vetor >>");

        for(int i = 0; i < 6; i++){
            System.out.print("Entre com o valor " + (i+1) + ": ");
            vetor[i] = sc.nextInt();
        }
        System.out.println("A ordem inversa dos números é: ");
        for(int i = 5; i > -1; i--){

            System.out.print(vetor[i]+ " ");
        }
    }
}