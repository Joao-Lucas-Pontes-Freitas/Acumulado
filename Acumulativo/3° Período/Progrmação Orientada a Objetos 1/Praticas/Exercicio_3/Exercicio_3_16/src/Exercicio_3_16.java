import java.util.Scanner;
public class Exercicio_3_16{
    public static void main(String[] args){

        Scanner sc = new Scanner (System.in);
        int []v = new int[8];
        int i;
        int j;
        int x;
        int cont;

        System.out.println("<< Valores iguais  >>");

        for(i = 0; i < 8; i++) {
            System.out.print("Entre com o número " + (i+1) + ": ");
            v[i] = sc.nextInt();
        }

        System.out.println("\nValores repetidos: ");

        for(i = 0; i < 8; i++){
            for(j = i+1; j < 8; j++){
                if(v[i] > v[j]){
                    x = v[i];
                    v[i] = v[j];
                    v[j] = x;
                }
            }
        }

        cont = 1;
        for(i = 1; i < 8; i++) {
            if(v[i] == v[i-1])
                cont++;
            else{
                if(cont > 1)
                    System.out.print(v[i-1] + " aparece " + cont + " vezes\n");
                cont = 1;
            }
        }
        if(cont > 1)
            System.out.print(v[i-1] + " aparece " + cont + " vezes\n");
    }
}