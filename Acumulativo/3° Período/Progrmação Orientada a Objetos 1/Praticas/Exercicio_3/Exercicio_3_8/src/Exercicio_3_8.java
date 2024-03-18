import java.lang.Math;
import java.util.Scanner;
public class Exercicio_3_8{
    public static void main(String[] args){

        Scanner sc = new Scanner (System.in);

        int vetor[] = new int[5];

        System.out.println("<< Listando um vetor >>");

        for(int i = 0; i < 5; i++){
            System.out.print("Entre com o valor " + (i+1) + ": ");
            vetor[i] = sc.nextInt();
        }
        double desvio = 0;
        float media = 0;

        System.out.println("Os valores lidos são: ");
        for(int i = 0; i < 5; i++){
            System.out.print(vetor[i]+ " ");
            media += vetor[i];
        }
        media = media/5;
        for(int i = 0; i < 5; i++){
            desvio += (vetor[i]-media)*(vetor[i]-media);
        }
        desvio = desvio/4;
        desvio = Math.sqrt(desvio);

        System.out.println("\nA média é: " + (media) + " e o desvio-padrão é "+ desvio);
    }
}