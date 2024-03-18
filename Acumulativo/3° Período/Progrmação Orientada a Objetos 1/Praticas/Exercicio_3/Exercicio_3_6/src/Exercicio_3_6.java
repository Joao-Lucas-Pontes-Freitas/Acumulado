import java.util.Scanner;
public class Exercicio_3_6{
    public static void main(String[] args){

        Scanner sc = new Scanner (System.in);

        int vetor[] = new int[5];

        System.out.println("<< Listando um vetor >>");

        for(int i = 0; i < 5; i++){
            System.out.print("Entre com o valor " + (i+1) + ": ");
            vetor[i] = sc.nextInt();
        }
        int maior = vetor[0];
        int l_maior = 0;
        int menor = vetor[0];
        int l_menor = 0;
        float soma = 0;

        System.out.println("Os valores lidos são: ");
        for(int i = 0; i < 5; i++){
            System.out.print(vetor[i]+ " ");
            if(vetor[i] > maior) {
                maior = vetor[i];
                l_maior = i;
            }
            if(vetor[i] < menor) {
                menor = vetor[i];
                l_menor = i;
            }
            soma += vetor[i];
        }
        System.out.println("\nO maior valor é: " + maior + ", localizado na posição " + l_maior + " do vetor");
        System.out.println("O menor valor é: " + menor + ", localizado na posição " + l_menor + " do vetor");
        System.out.println("A média é: " + (soma/5));
    }
}