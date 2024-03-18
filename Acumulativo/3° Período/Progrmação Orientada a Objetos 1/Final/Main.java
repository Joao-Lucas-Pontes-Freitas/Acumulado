import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.io.File;
import java.util.Scanner;

public class Main {
    public static void main(String[] args)  {
        Menu.inicializaDados();

        ArrayList<Funcionario> funcionarios = new ArrayList<>();
        ArrayList<Agencia> agencias = new ArrayList<>();
        ArrayList<Gerente> gerentes = new ArrayList<>();

        Gerente[] gerentesTMP = Menu.inicializaGerentesCalculo();
        Classificador.ordena(gerentesTMP);
        gerentes.add(gerentesTMP[0]);
        gerentes.add(gerentesTMP[1]);
        gerentes.add(gerentesTMP[2]);
        funcionarios.add(gerentesTMP[0]);
        funcionarios.add(gerentesTMP[1]);
        funcionarios.add(gerentesTMP[2]);

        Agencia[] agenciaTMP = Menu.inicializaAgencias(gerentesTMP);
        agencias.add(agenciaTMP[0]);
        agencias.add(agenciaTMP[1]);
        agencias.add(agenciaTMP[2]);
        agenciaTMP = null;
        int opcao = -1;
        System.out.println();
        Menu.voltarAoMenu();
        Scanner escolha = new Scanner(System.in);
        while (opcao != 0) {
            Menu.mostraMenu();

            System.out.print("Escolha uma opção: ");
            opcao = escolha.nextInt();
            escolha.nextLine();
            switch (opcao) {
                case 0 -> System.out.println("\n---\nPrograma encerrado.");
                case 1 -> {
                    Cliente cliente = Menu.cadastrarCliente();
                    DadosClientes.cadastrar(cliente);
                    System.out.println("\n---\nCliente cadastrado com sucesso!");
                    Menu.voltarAoMenu();
                }
                case 2 -> {
                    Funcionario funcionario = Menu.cadastrarFuncionario();
                    funcionarios.add(funcionario);
                    System.out.println("\n---\nFuncionário cadastrado com sucesso!");
                    Menu.voltarAoMenu();
                }
                case 3 -> {
                    Gerente gerente = Menu.cadastrarGerente();
                    gerentes.add(gerente);
                    System.out.println("\n---\nGerente cadastrado com sucesso!");
                    Menu.voltarAoMenu();
                }
                case 4 -> {
                    Agencia agencia = Menu.cadastrarAgencia();
                    agencias.add(agencia);
                    System.out.println("\n---\nAgência cadastrada com sucesso!");
                    Menu.voltarAoMenu();
                }
                case 5 -> {
                    Cliente cliente = Menu.escolherCliente(), clienteConjunto = null;
                    if (cliente == null)
                        break;
                    System.out.print("A conta será conjunta? (sim ou não)\n-> ");
                    String resposta = escolha.nextLine();
                    boolean conjunta = resposta.compareToIgnoreCase("sim") == 0;
                    if (conjunta) {
                        System.out.println("Escolha o cliente conjunto:");
                        clienteConjunto = Menu.escolherCliente();
                    }
                    Conta conta = Menu.criarConta(cliente, clienteConjunto);
                    DadosContas.cadastrar(conta);
                    System.out.println("\n---\nConta bancária criada com sucesso!");
                    Menu.voltarAoMenu();
                }
                case 6 -> {
                    Menu.realizarTransacao();
                    Menu.voltarAoMenu();
                }
                case 7 -> {
                    Menu.mostraClientes();
                    Menu.voltarAoMenu();
                }
                case 8 -> {
                    Menu.mostraContas();
                    Menu.voltarAoMenu();
                }
                case 9 -> {
                    Menu.mostraFuncionarios(funcionarios);
                    System.out.println("------");
                    Menu.voltarAoMenu();
                }
                case 10 -> {
                    Menu.mostraGerentes(gerentes);
                    System.out.println("------");
                    Menu.voltarAoMenu();
                }
                case 11 -> {
                    Menu.mostraAgencias(agencias);
                    Menu.voltarAoMenu();
                }
                case 12 -> {
                    Menu.dadosConta();
                    Menu.voltarAoMenu();
                }
                case 13 -> {
                    Menu.limparDados();
                }
                case 14 -> {
                    Menu.desativarConta();
                }
                default -> System.out.println("Opção inválida!");
            }
        }
    }
}
