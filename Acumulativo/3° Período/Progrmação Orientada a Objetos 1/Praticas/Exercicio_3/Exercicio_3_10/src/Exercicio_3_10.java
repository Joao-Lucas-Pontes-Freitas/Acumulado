import java.util.Scanner;
public class Exercicio_3_10{
    public static void main(String[] args){

        Scanner sc = new Scanner (System.in);

        int A[] = new int[3];
        int B[] = new int[3];
        int C[] = new int[3];

        System.out.println("<< Subtração de vetores >>");

        for(int i = 0; i < 3; i++){
            System.out.print("Digite o valor " + (i+1) + " de A: ");
            A[i] = sc.nextInt();
        }

        for(int i = 0; i < 3; i++){
            System.out.print("Digite o valor " + (i+1) + " de B: ");
            B[i] = sc.nextInt();
        }

        for(int i = 0; i < 3; i++){
            C[i] = A[i] - B[i];
        }

        System.out.println("\nO vetor C, definido como C = A-B é (" + C[0] + "," + C[1] + "," + C[2] + ")");
    }
}