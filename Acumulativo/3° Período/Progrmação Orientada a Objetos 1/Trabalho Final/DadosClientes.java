import java.util.ArrayList;
public class DadosClientes {
    private static ArrayList<Cliente> clientes;

    public static void inicializaClientes (){
        clientes = (ArrayList<Cliente>) Persist.recuperar("clientes.dat");
        if(clientes == null)
            clientes = new ArrayList<Cliente>();
    }

    public static void limparClientes() {
        clientes.clear();
        boolean sucesso = Persist.gravar(clientes, "contas.dat");
        if (!sucesso) {
            System.out.println("Erro ao gravar os dados das Contas");
        }
    }

    public static void cadastrar(Cliente cliente) {
        clientes.add(cliente);
        boolean sucesso = Persist.gravar(clientes, "clientes.dat");
        if (!sucesso) {
            System.out.println("Erro ao gravar os dados dos clientes");
        }
    }
}
