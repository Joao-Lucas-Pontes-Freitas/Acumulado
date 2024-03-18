import java.util.Scanner;
public class Exercicio_3_7{
    public static void main(String[] args){

        Scanner sc = new Scanner (System.in);

        float vetor[] = new float[5];

        System.out.println("<< Normalizando as notas >>");

        for(int i = 0; i < 5; i++){
            System.out.print("Entre com a nota do aluno " + (i+1) + ": ");
            vetor[i] = sc.nextInt();
        }
        float maior = vetor[0];
        float nivel;

        for(int i = 0; i < 5; i++) {
            if (vetor[i] > maior)
                maior = vetor[i];
        }

        nivel = 100/maior;

        for(int i = 0; i < 5; i++){
            vetor[i] = vetor[i]*nivel;
        }

        System.out.println("\nNotas normalizadas\n");
        for(int i = 0; i < 5; i++){
            System.out.println("A nota do aluno " + (i+1) + " é " + vetor[i]);
        }
    }
}