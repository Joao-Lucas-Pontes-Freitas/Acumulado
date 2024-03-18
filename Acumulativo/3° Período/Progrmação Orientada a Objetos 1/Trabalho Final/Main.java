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
        ArrayList<Funcionario> funcionarios = new ArrayList<>();
        ArrayList<Agencia> agencias = new ArrayList<>();
        ArrayList<Gerente> gerentes = new ArrayList<>();

        Agencia[] agenciaTMP = Menu.inicializaAgencias();
        agencias.add(agenciaTMP[0]);
        agencias.add(agenciaTMP[1]);
        agencias.add(agenciaTMP[2]);
        agenciaTMP = null;
        int opcao = -1;
        Scanner escolha = new Scanner(System.in);
        while (opcao != 0) {
            Menu.mostraMenu();

            System.out.print("Escolha uma opção: ");
            opcao = escolha.nextInt();
            escolha.nextLine();
            switch (opcao) {
                case 0 -> System.out.println("\n---\nPrograma encerrado.");
                case 1 -> {
                    System.out.println("\n---\nCadastrar cliente.");
                    Cliente cliente = Menu.cadastrarCliente();
                    DadosClientes.cadastrar(cliente);
                    System.out.println("\n---\nCliente cadastrado com sucesso!");
                }
                case 2 -> {
                    System.out.println("\n---\nCadastrar funcionário.");
                    Funcionario funcionario = Menu.cadastrarFuncionario();
                    funcionarios.add(funcionario);
                    System.out.println("\n---\nFuncionário cadastrado com sucesso!");
                }
                case 3 -> {
                    System.out.println("\n---\nCadastrar gerente.");
                    Gerente gerente = Menu.cadastrarGerente();
                    gerentes.add(gerente);
                    System.out.println("\n---\nGerente cadastrado com sucesso!");
                }
                case 4 -> {
                    System.out.println("\n---\nCadastrar agência.");
                    Agencia agencia = Menu.cadastrarAgencia();
                    System.out.println("\n---\nAgência cadastrada com sucesso!");
                }
                case 5 -> {
                    System.out.println("\n---\nCriar conta bancária.");
                    System.out.println("Escolha o cliente da conta:");
                    Cliente cliente = Menu.escolherCliente(), clienteConjunto = null;
                    System.out.println("A conta será conjunta? (sim ou não)");
                    String resposta = escolha.nextLine();
                    boolean conjunta = resposta.compareToIgnoreCase("sim") == 0;
                    if (conjunta) {
                        System.out.println("Escolha o cliente conjunto:");
                        clienteConjunto = Menu.escolherCliente();
                    }
                    Conta conta = Menu.criarConta(cliente, clienteConjunto);
                    DadosContas.cadastrar(conta);
                    System.out.println("\n---\nConta bancária criada com sucesso!");
                    conta.imprimeDados();
                }
                case 6 -> {
                    System.out.println("\n---\nContas disponíveis para transações.");

                    Transacao transacao = Menu.realizarTransacao();
                    System.out.println("\n---\nTransação realizada com sucesso!");
                }
                case 7 -> {
                    System.out.println("\n---\nMostrar clientes.");
                    Menu.mostraClientes();
                }
                case 8 -> {
                    System.out.println("\n---\nMostrar contas.");
                    Menu.mostraContas();
                }
                case 9 -> {
                    System.out.println("\n---\nMostrar funcionários.");
//                Menu.mostraFuncionarios(funcionarios);
                }
                case 10 -> {
                    System.out.println("\n---\nMostrar gerentes.");
//                Menu.mostraGerentes(gerentes);
                }
                case 11 -> {
                    System.out.println("\n---\nMostrar agencias.");
                    Menu.mostraAgencias(agencias);
                }
                case 12 -> {
                    System.out.println("\n---\nMostrar dados da conta de um cliente.");
//                Menu.mostraDadosContaCliente();
                }
                case 13 -> {
                    System.out.println("\n---\nLimpar Base de dados.");
                    Menu.limparDados();
                }
                case 14 -> {
                    System.out.println("\n---\nDesativar conta.");
                    desativar:
                    {
                        System.out.println(" - Contas disponíveis:");
                        Menu.mostraContas();
                        System.out.println("--------");
                        System.out.print("Digite o número da conta a ser desativado: ");
                        int numeroConta = escolha.nextInt();
                        ArrayList<Conta> contas = (ArrayList<Conta>) Persist.recuperar("contas.dat");
                        assert contas != null;
                        Conta desativada = null;
                        int i;
                        for (i = contas.size(); i > 0; i--) {
                            if (contas.get(contas.size() - i).getNumeroConta() == numeroConta) {
                                desativada = contas.get(contas.size() - i);
                                contas.remove(contas.size() - i);
                                break;
                            }
                        }
                        if (desativada != null) {
                            senhas:
                            {
                                System.out.print("Digite a senha da conta: ");
                                int senha = escolha.nextInt();
                                boolean success = false;
                                try {
                                    desativada.encerrarConta(senha);
                                    break senhas;
                                } catch (SenhaInvalidaException e) {
                                    System.out.println(e.getMessage());
                                }
                            }
                            contas.add(desativada);
                            DadosContas.limparContas();
                            DadosContas.inicializaContas();
                            for (Conta c : contas) {
                                DadosContas.cadastrar(c);
                            }
                            break desativar;
                        }
                        System.out.println("Número da conta não existe! Digite outro");
                    }
                }
            }
        }
    }
}
