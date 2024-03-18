import java.util.Scanner;
public class Exercicio_3_12{
    public static void main(String[] args){

        Scanner sc = new Scanner (System.in);

        float vet[] = new float[4];
        float prob[] = new float[4];
        int maior = 0;
        float soma = 0;

        System.out.println("<< Probabilidade >>");
        System.out.println("\nDigite a quantidade de bolinhas");

        System.out.print("Verde: ");
        vet[0] = sc.nextFloat();
        System.out.print("Azul: ");
        vet[1] = sc.nextFloat();
        System.out.print("Amarela: ");
        vet[2] = sc.nextFloat();
        System.out.print("Vermelha: ");
        vet[3] = sc.nextFloat();

        for(int i = 0; i < 4; i++) {
            if (vet[i] > maior) {
                maior = i;
            }
            soma += vet[i];
        }

        for(int i = 0; i < 4; i++){
            prob[i] = (vet[i]/soma*100);
        }

        System.out.println(soma);

        System.out.println("\nProbabilidades");
        System.out.print("\nVerde: " + prob[0] + "%"); if(maior == 0) System.out.print(" << Maior probabilidade");
        System.out.print("\nAzul: " + prob[1] + "%"); if(maior == 1) System.out.print(" << Maior probabilidade");
        System.out.print("\nAmarela: " + prob[2] + "%"); if(maior == 2) System.out.print(" << Maior probabilidade");
        System.out.print("\nVermelha: " + prob[3] + "%"); if(maior == 3) System.out.print(" << Maior probabilidade");

    }
}