import java.util.Scanner;
public class Exercicio_3_11{
    public static void main(String[] args){

        Scanner sc = new Scanner (System.in);

        int []v = new int[5];
        int []v1 = new int[5];
        int []v2 = new int[5];
        int t1 = 0;
        int t2 = 0;

        System.out.println("<< Subtração de vetores >>");

        for(int i = 0; i < 5; i++){
            System.out.print("Digite o valor " + (i+1) + ": ");
            v[i] = sc.nextInt();
        }

        for(int i = 0; i < 5; i++){
            if(v[i] % 2 == 0) {
                v2[t2] = v[i];
                t2++;
            }
            else {
                v1[t1] = v[i];
                t1++;
            }
        }

        System.out.print("\nÍmpares: ");
        for(int i = 0; i < t1; i++){
            System.out.print(v1[i]);
            if(i != t1-1)
                System.out.print(", ");
        }

        System.out.print("\nPares: ");
        for(int i = 0; i < t2; i++){
            System.out.print(v2[i]);
            if(i != t2-1)
                System.out.print(", ");
        }
    }
}