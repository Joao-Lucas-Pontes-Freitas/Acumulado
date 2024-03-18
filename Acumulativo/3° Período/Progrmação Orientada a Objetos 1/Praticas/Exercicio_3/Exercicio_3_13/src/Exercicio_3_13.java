import java.util.Scanner;
public class Exercicio_3_13{
    public static void main(String[] args){

        Scanner sc = new Scanner (System.in);

        int []v = new int[5];

        System.out.println("<< Zerando negativos  >>");

        for(int i = 0; i < 5; i++) {
            System.out.print("Entre com o número " + (i+1) + ": ");
            v[i] = sc.nextInt();
            if(v[i] < 0)
                v[i] = 0;
        }

        System.out.print("\nZerando os negativos, obtém-se: ");

        for(int i = 0; i < 5; i++) {
            System.out.print(v[i] + " ");
        }
    }
}