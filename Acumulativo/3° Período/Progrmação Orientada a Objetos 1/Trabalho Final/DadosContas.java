import java.util.ArrayList;

public class DadosContas {
    private static ArrayList<Conta> contas;

    public static void inicializaContas() {
        contas = (ArrayList<Conta>) Persist.recuperar("contas.dat");
        if(contas == null)
            contas = new ArrayList<Conta>();
    }

    public static ArrayList<Conta> getContas() {
        return contas;
    }

    public static void limparContas() {
        contas.clear();
        boolean sucesso = Persist.gravar(contas, "contas.dat");
        if (!sucesso) {
            System.out.println("Erro ao gravar os dados das Contas");
        }
    }

    public static void cadastrar(Conta conta) {
        contas.add(conta);
        boolean sucesso = Persist.gravar(contas, "contas.dat");
        if (!sucesso) {
            System.out.println("Erro ao gravar os dados das Contas");
        }
    }
}



// OLD

//import java.util.ArrayList;
//public class DadosContas {
//    private static ArrayList<ContaCorrente> contas;
//
//    public static void inicializaContas (){
//        contas = (ArrayList<ContaCorrente>) Persist.recuperar("contas.dat");
//        if(contas == null)
//            contas = new ArrayList<ContaCorrente>();
//    }
//
//    public static void cadastrar(ContaCorrente conta) {
//        contas.add(conta);
//        boolean sucesso = Persist.gravar(contas, "contas.dat");
//        if (!sucesso) {
//            System.out.println("Erro ao gravar os dados das Contas");
//        }
//    }
//
//    public static int getNumeroContas() {
//        return contas.size();
//    }
//}