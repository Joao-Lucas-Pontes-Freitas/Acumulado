import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Scanner;

public class Menu {
    Agencia[] agencias = new Agencia[3];
    static int numeroConta = 1240;

    public static Agencia[] inicializaAgencias() {
        Gerente[] gerentes = new Gerente[3];
        gerentes[0] = new Gerente("12345678900", "Ana Silva", "Rua das Flores, 123, Cidade X, Estado Y",
                "Solteira", LocalDate.of(1980,5,10), 987654, "12345678", "Feminino",
                "Gerente de Vendas", 8000, LocalDate.of(2010,1,1), LocalDate.of(2015,1,1), true);
        gerentes[1] = new Gerente(" 98765432100", "Pedro Santos", "Avenida das Palmeiras, 456, Cidade Z, Estado W",
                "Casado", LocalDate.of(1975,11,20), 345679, " 87654321", "Masculino",
                "Gerente de Produção", 10000, LocalDate.of(2008,7,1), LocalDate.of(2013,7,1), true);
        gerentes[2] = new Gerente("65432198700", "Maria Oliveira", "Rua dos Pinheiros, 789, Cidade A, Estado B",
                "Divorciada", LocalDate.of(1985,3,15), 890123, "56781234", "Feminino",
                "Gerente de Recursos Humanos", 9000, LocalDate.of(2012,3,1), LocalDate.of(2017,3,1), true);

        gerentes[0].calcularSalario(8000);
        gerentes[1].calcularSalario(10000);
        gerentes[2].calcularSalario(9000);

        Agencia[] agencias = new Agencia[3];
        agencias[0] = new Agencia(1111, "Agência Central", "Avenida Principal, 123", "Cidade A", "Estado X", "Centro", gerentes[0]);
        agencias[1] = new Agencia(2222, "Agência Real", "Rua das Casas, 456", "Cidade B", "Estado Y", "Jardim das Flores", gerentes[1]);
        agencias[2] = new Agencia(3333, "Agência Viagens Monetárias", "Travessa Turística, 789", "Cidade C", "Estado Z", "Praia Grande", gerentes[2]);

        return agencias;
    }

    private static void escolhaAgencias(Agencia[] agencias) {
        int cont = 1;
        for (Agencia a : agencias) {
            System.out.println("Agência " + cont++ + ":\n" + "Nome: " + a.getNomeFicticio());
            System.out.println("Número da agência: " + a.getNumero());
            System.out.println("-----");
        }
    }

    public static void mostraAgencias(ArrayList<Agencia> agencias) {
        assert agencias != null;
        int contador = 1;
        for (Agencia a : agencias) {
            System.out.println("-----------\nAgência: " + contador++ + "\n----");
            try {
                a.imprimeDadosAgencia();
            } catch (RuntimeException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    public static void mostraMenu() {
        //TODO: fiz ate conta bancaria e n fiz agencia.
        System.out.println("----------Menu----------");
        System.out.println("1) Cadastrar cliente.");
        System.out.println("2) Cadastrar funcionário.");
        System.out.println("3) Cadastrar gerente.");
        System.out.println("4) Cadastrar agência.");
        System.out.println("5) Criar conta bancária.");
        System.out.println("6) Realizar transação.");
        System.out.println("7) Mostrar clientes.");
        System.out.println("8) Mostrar contas.");
        System.out.println("9) Mostrar funcionários.");
        System.out.println("10) Mostrar gerentes.");
        System.out.println("11) Mostrar agencias.");
        System.out.println("12) Mostrar dados da conta de um cliente.");
        System.out.println("12) Limpar Base de dados.");
        System.out.println("\n---\n0) Encerrar.");
        System.out.println("------------------------");
    }

    public static Transacao realizarTransacao() {
        return null;
    }

    public static Agencia cadastrarAgencia() {
        Scanner sc = new Scanner(System.in);

        System.out.println(" - Número da agência: ");
        int numero = sc.nextInt();
        sc.nextLine();

        System.out.println(" - Nome da agência: ");
        String nome = sc.nextLine();

        System.out.println(" - Endereço da agência: ");
        String endereco = sc.nextLine();

        System.out.println(" - Cidade da agência: ");
        String cidade = sc.nextLine();

        System.out.println(" - Estado da agência: ");
        String estado = sc.nextLine();

        System.out.println(" - Bairro da agência: ");
        String bairro = sc.nextLine();

        System.out.println(" - Gerente da agência: ");
        Gerente gerente = cadastrarGerente();

        return new Agencia(numero, nome, endereco, cidade, estado, bairro, gerente);
    }

    public static Cliente cadastrarCliente() {
        Scanner sc = new Scanner(System.in);
        System.out.println("\n---\nPreencha com os dados do cliente: ");

        System.out.print(" - Nome: ");
        String nome = sc.nextLine();

        System.out.print(" - CPF: ");
        String cpf = sc.nextLine();

        System.out.print(" - Endereço: ");
        String endereco = sc.nextLine();

        System.out.print(" - Estado civil: ");
        String estadoCivil = sc.nextLine();

        System.out.print(" - Escolaridade: ");
        String escolaridade = sc.nextLine();

        System.out.println(" - Data de nascimento:");
        System.out.print(" --> Dia: ");
        int dia = sc.nextInt();
        System.out.print(" --> Mês: ");
        int mes = sc.nextInt();
        System.out.print(" --> Ano: ");
        int ano = sc.nextInt();

        return new Cliente(cpf, nome, endereco, estadoCivil, escolaridade, LocalDate.of(ano, mes, dia));
    }

    public static Funcionario cadastrarFuncionario() {
        Scanner sc = new Scanner(System.in);
        System.out.println("\n---\nPreencha com os dados do funcionário: ");

        System.out.print(" - Nome: ");
        String nome = sc.nextLine();

        System.out.print(" - CPF: ");
        String cpf = sc.nextLine();

        System.out.print(" - RG: ");
        String rg = sc.nextLine();

        System.out.print(" - Endereço: ");
        String endereco = sc.nextLine();

        System.out.print(" - Sexo: ");
        String sexo = sc.nextLine();

        System.out.print(" - Cargo: ");
        String cargo = sc.nextLine();

        System.out.print(" - Estado civil: ");
        String estadoCivil = sc.nextLine();

        System.out.print(" - Salário: ");
        double salario = sc.nextDouble();

        System.out.print(" - Número da carteira: ");
        int carteira = sc.nextInt();

        System.out.println(" - Data de nascimento:");
        System.out.print(" --> Dia: ");
        int dia = sc.nextInt();
        System.out.print(" --> Mês: ");
        int mes = sc.nextInt();
        System.out.print(" --> Ano: ");
        int ano = sc.nextInt();

        System.out.println(" - Data de ingresso na empresa:");
        System.out.print(" --> Dia: ");
        int diaI = sc.nextInt();
        System.out.print(" --> Mês: ");
        int mesI = sc.nextInt();
        System.out.print(" --> Ano: ");
        int anoI = sc.nextInt();

        return new Funcionario(cpf, nome, endereco, estadoCivil, LocalDate.of(ano, mes, dia), carteira, rg, sexo, cargo, salario, LocalDate.of(anoI, mesI, diaI));
    }

    public static Gerente cadastrarGerente() {
        Scanner sc = new Scanner(System.in);
        Funcionario fTemp = cadastrarFuncionario();

        System.out.println(" - Data de ingresso na gerencia:");
        System.out.print(" --> Dia: ");
        int diaIG = sc.nextInt();
        System.out.print(" --> Mês: ");
        int mesIG = sc.nextInt();
        System.out.print(" --> Ano: ");
        int anoIG = sc.nextInt();

        System.out.println(" - Possui curso de gerência? (sim ou não)");
        String resposta = sc.nextLine();
        boolean curso = resposta.compareToIgnoreCase("sim") == 0;

        return new Gerente(fTemp.getCPF(), fTemp.getNome(), fTemp.getEndereco(), fTemp.getEstadoCivil(), LocalDate.of(fTemp.getAnoNascimento(),
                fTemp.getMesNascimento(), fTemp.getDiaNascimento()), fTemp.getNumeroCarteira(), fTemp.getRg(), fTemp.getSexo(),
                fTemp.getCargo(), fTemp.getSalario(), LocalDate.of( fTemp.getAnoIngresso(), fTemp.getMesIngresso(), fTemp.getDiaIngresso()),
                LocalDate.of(anoIG, mesIG, diaIG), curso);
    }

    public static Conta criarConta(Cliente cliente, Cliente contaConjunta) {
        Scanner sc = new Scanner(System.in);
        boolean out;
        do {
            out = true;
            System.out.println("Deseja criar qual tipo de conta?");
            System.out.println(" - 1: Conta corrente.");
            System.out.println(" - 2: Conta poupança.");
            System.out.println(" - 3: Conta salário.");
            int escolha = sc.nextInt();

            int agencia;
            Agencia[] agencias = inicializaAgencias();
            System.out.println("Escolha a agência desejada: ");
            escolhaAgencias(agencias);
            agencia = sc.nextInt() - 1;

            System.out.println("Digite a senha da conta: ");
            int senha = sc.nextInt();
            
            double saldo = sc.nextDouble();
            switch (escolha) {
                case 1 -> {
                    return criarContaCorrente(cliente, contaConjunta, senha, agencias[agencia]);
                }
                case 2 -> {
                    return criarContaPoupanca(cliente, contaConjunta, senha, agencias[agencia]);
                }
                case 3 -> {
                    return criarContaSalario(cliente, contaConjunta, senha, agencias[agencia]);
                }
                default -> System.out.println("Opção não existe!");
            }
        } while (true);
    }

    private static Conta criarContaCorrente(Cliente cliente, Cliente contaConjunta, int senha, Agencia agencia) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Digite as características da conta corrente: ");
        System.out.println(" - Limite cheque especial: ");
        double limite = sc.nextDouble();
        System.out.println(" - Taxa administrativa: ");
        double taxaAdm = sc.nextDouble();

        numeroConta++;
        return new ContaCorrente(senha, numeroConta, 0, limite, taxaAdm, agencia, cliente, contaConjunta);
    }

    private static Conta criarContaPoupanca(Cliente cliente, Cliente contaConjunta, int senha, Agencia agencia) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Digite as características da conta poupança: ");
        System.out.println(" - Rendimento mensal: ");
        double rendimentoMes = sc.nextDouble();

        numeroConta++;
        return new ContaPoupanca(senha, numeroConta, 0, rendimentoMes, agencia, cliente, contaConjunta);
    }

    private static Conta criarContaSalario(Cliente cliente, Cliente contaConjunta, int senha, Agencia agencia) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Digite as características da conta corrente: ");
        System.out.println(" - Limite saque: ");
        double saque = sc.nextDouble();
        System.out.println(" - Limite transferencia: ");
        double transferencia = sc.nextDouble();

        numeroConta++;
        return new ContaSalario(senha, numeroConta, 0, saque, transferencia, agencia, cliente, contaConjunta);
    }

    public static Cliente escolherCliente() {
        Scanner escolha = new Scanner(System.in);
        mostraClientes();
        System.out.println("--------\nCliente desejado: ");
        int clienteIndex = escolha.nextInt() - 1;

        ArrayList<Cliente> clientes = (ArrayList<Cliente>) Persist.recuperar("contas.dat");
        assert clientes != null;

        return clientes.get(clienteIndex);
    }

    public static void filtraOpcao() {

    }

    public static void limparDados() {
        DadosContas.limparContas();
        DadosClientes.limparClientes();
    }

    public static void mostraContas() {
        ArrayList<Conta> contas = (ArrayList<Conta>) Persist.recuperar("contas.dat");
        assert contas != null;
        int contador = 1;
        for (Conta conta : contas) {
            System.out.println("-----------\nConta: " + contador++ + "\n----");
            try {
                conta.imprimeDados();
            } catch (RuntimeException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    public static void mostraClientes() {
        ArrayList<Cliente> clientes = (ArrayList<Cliente>) Persist.recuperar("contas.dat");
        assert clientes != null;
        int contador = 1;
        for (Cliente cliente : clientes) {
            System.out.println("-----------\nConta: " + contador++ + "\n----");
            try {
                cliente.imprimeCliente();
            } catch (RuntimeException e) {
                System.out.println(e.getMessage());
            }
        }
    }
}
