import java.util.Scanner;
public class Tentativa{
    public static void main(String[] args){

        Scanner sc = new Scanner (System.in);

        String nome[] = new String[4];
        int qtd_estoque[] = new int[4];
        float preco[] = new float[4];

        for (int i = 0; i < 4; i++){
            preco[i] = sc.nextFloat();
            clearBuffer(sc);
            nome[i] = sc.nextLine();
            qtd_estoque[i] = sc.nextInt();
        }

        System.out.println("\nAumentando o preco em 10%% do produto 1 e 3");
        preco[0] = altera_preco(preco[0], 10);
        preco[2] = altera_preco(preco[2], 10);

        System.out.println("\nReduzindo o preco em 5%% do produto 2");
        float tmp = altera_preco(preco[1],-5);
        if (tmp == -1)
            System.out.println("\n\nErro: preco nao alterado. Porcentagem invalida\n");
        else{
            preco[1] = tmp;
            System.out.println("\n\nPreco alterado com sucesso");
        }

        System.out.println("\nAlterando o preco do prod. 3");
        tmp = altera_preco(preco[3],-110);
        if (tmp == -1)
            System.out.println("\n\nErro: preco nao alterado. Porcentagem invalida\n");
        else
            preco[3] = tmp;

        System.out.println("\nProdutos Cadastrados:\n");
        for (int i = 0; i < 4; i++){
            System.out.println("Produto: " + nome[i] + " Preco: " + preco[i] + " Estoque:" + qtd_estoque[i]);
        }
    }
    static float altera_preco(float preco, float porcentagem){
        float temp;
        if (porcentagem > -100){
            temp = 1 + porcentagem/100;
            preco = preco*temp;
            return preco;
        }
        else {
            return -1;
        }
    }

    public static void clearBuffer(Scanner scanner) {
        if (scanner.hasNextLine()) {
            scanner.nextLine();
        }
    }

}