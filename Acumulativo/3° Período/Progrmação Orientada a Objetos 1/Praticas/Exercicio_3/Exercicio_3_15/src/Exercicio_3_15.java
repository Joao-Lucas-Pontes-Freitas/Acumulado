import java.util.Scanner;
public class Exercicio_3_15{
    public static void main(String[] args){

        Scanner sc = new Scanner (System.in);
        int []v = new int[8];
        int c;
        int x = 0;
        int []v2 = new int[8];

        for(int i = 0; i < 8; i++)
            v2[i] = 0;

        System.out.println("<< Valores iguais  >>");

        for(int i = 0; i < 8; i++) {
            System.out.print("Entre com o número " + (i+1) + ": ");
            v[i] = sc.nextInt();
        }

        System.out.print("\nValores repetidos: ");

        for(int i = 0; i < 8; i++){
            c = 0;
            for(int j = 0; j < 8; j++){
                if(v[i] == v[j] && v[i]!= 0){
                    c++;
                    if(c > 1){
                        v2[x] = v[i];
                        v[j] = 0;
                        v[i] = 0;
                        x++;
                        break;
                    }
                }
            }
        }

        for(int i = 0; i < x; i++) {
            if(i < x-1)
                System.out.print(v2[i] + ", ");
            else
                System.out.print(v2[i]);
        }
    }
}