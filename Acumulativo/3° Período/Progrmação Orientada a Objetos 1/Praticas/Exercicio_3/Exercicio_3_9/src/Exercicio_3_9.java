import java.util.Scanner;
public class Exercicio_3_9{
    public static void main(String[] args){

        Scanner sc = new Scanner (System.in);

        int alunos;
        float media = 0;

        System.out.println("<< Média de n alunos. Máximo 100 alunos  >>");
        System.out.print("Entre com o número de alunos: ");
        alunos = sc.nextInt();

        if(alunos > 100){
            System.out.print("Erro! O número máximo de alunos permitido é 100.");
            return;
        }

        int vetor[] = new int[alunos];

        for(int i = 0; i < alunos; i++){
            System.out.print("Digite a nota do aluno " + (i+1) + ": ");
            vetor[i] = sc.nextInt();
        }

        System.out.println("\nRelatório de notas: ");
        for(int i = 0; i < alunos; i++){
            System.out.println("A nota do aluno " + (i+1) + " é: " + vetor[i]);
            media += vetor[i];
        }

        System.out.println("A média é: " + (media/alunos));
    }
}