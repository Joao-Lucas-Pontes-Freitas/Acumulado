import java.util.Scanner;
public class Exercicio_3_5{
    public static void main(String[] args){

        Scanner sc = new Scanner (System.in);

        int vetor[] = new int[5];

        System.out.println("<< Listando um vetor >>");

        for(int i = 0; i < 5; i++){
            System.out.print("Entre com o valor " + (i+1) + ": ");
            vetor[i] = sc.nextInt();
        }
        int maior = vetor[0];
        int menor = vetor[0];
        float soma = 0;

        System.out.println("Os valores lidos são: ");
        for(int i = 0; i < 5; i++){
            System.out.print(vetor[i]+ " ");
            if(vetor[i] > maior)
                maior = vetor[i];
            if(vetor[i] < menor)
                menor = vetor[i];
            soma += vetor[i];
        }
        System.out.println("\nO maior valor é: " + maior);
        System.out.println("O menor valor é: " + menor);
        System.out.println("A média é: " + (soma/5));
    }
}