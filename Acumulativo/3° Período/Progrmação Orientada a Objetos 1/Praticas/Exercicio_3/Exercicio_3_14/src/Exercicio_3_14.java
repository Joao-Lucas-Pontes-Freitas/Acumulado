import java.util.Scanner;
public class Exercicio_3_14{
    public static void main(String[] args){

        Scanner sc = new Scanner (System.in);
        System.out.println("<< Universidade X >>");

        int x;

        System.out.print("Quantos alunos serão cadastrados: ");
        x = sc.nextInt();

        if(x > 10000){
            System.out.print("Número inválido! Quantos alunos serão cadastrados: ");
            x = sc.nextInt();
        }

        int []m = new int[x];
        float []cra = new float[x];
        char []c = new char[x];

        for(int i = 0; i < x; i++) {
            System.out.print("\nEntre com o número do aluno: ");
            m[i] = sc.nextInt();
            System.out.print("Entre com a classe social do aluno: ");
            c[i] = sc.next().charAt(0);
            System.out.print("Entre com o CRA do aluno: ");
            cra[i] = sc.nextFloat();
        }

        System.out.println("\n==== Alunos Cadastrados ====");

        for(int i = 0; i < x; i++) {
            System.out.println("Número: " + m[i] + " Classe Social: " + c[i] + " CRA: " + cra[i]);
        }
    }
}