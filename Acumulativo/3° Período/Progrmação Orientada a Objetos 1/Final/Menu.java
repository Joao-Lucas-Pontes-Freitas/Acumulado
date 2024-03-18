import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Scanner;

public class Menu {
    Agencia[] agencias = new Agencia[3];

    public static void inicializaDados() {
        DadosContas.inicializaContas();
        DadosClientes.inicializaClientes();
    }
    public static Agencia[] inicializaAgencias(Gerente[] gerentes) {
        Agencia[] agencias = new Agencia[3];
        agencias[0] = new Agencia(1111, "Agência Central", "Avenida Principal, 123", "Cidade A", "Estado X", "Centro", gerentes[0]);
        agencias[1] = new Agencia(2222, "Agência Real", "Rua das Casas, 456", "Cidade B", "Estado Y", "Jardim das Flores", gerentes[1]);
        agencias[2] = new Agencia(3333, "Agência Viagens Monetárias", "Travessa Turística, 789", "Cidade C", "Estado Z", "Praia Grande", gerentes[2]);

        return agencias;
    }

    private static Gerente[] inicializaGerentes() {
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

        return gerentes;
    }

    public static Gerente[] inicializaGerentesCalculo() {
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

        System.out.println("Salários antes de serem calculados:");
        for (Gerente g : gerentes) {
            System.out.println(" -> Gerente: " + g.getNome() + " (" + g.getSalario() + ")\n" + "\t\t\tgerente desde: " + g.getDataIngressoGerencia());
        }
        gerentes[0].calcularSalario(8000);
        gerentes[1].calcularSalario(10000);
        gerentes[2].calcularSalario(9000);

        System.out.println("Salários após de serem calculados:");
        for (Gerente g : gerentes) {
            System.out.println(" -> Gerente: " + g.getNome() + " (" + g.getSalario() + ")\n" + "\t\t\tgerente desde: " + g.getDataIngressoGerencia());
        }
        return gerentes;
    }

    private static void escolheAgencias(Agencia[] agencias) {
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
        System.out.println("11) Mostrar agências.");
        System.out.println("12) Mostrar dados da conta de um cliente.");
        System.out.println("13) Limpar banco de dados.");
        System.out.println("14) Desativar conta.");
        System.out.println("----\n0) Sair.");
        System.out.println("----------");
    }
    public static Agencia cadastrarAgencia() {
        Scanner sc = new Scanner(System.in);

        System.out.print(" - Número da agência (inteiro): ");
        int numero = sc.nextInt();
        sc.nextLine();

        System.out.print(" - Nome da agência: ");
        String nome = sc.nextLine();

        System.out.print(" - Endereço da agência: ");
        String endereco = sc.nextLine();

        System.out.print(" - Cidade da agência: ");
        String cidade = sc.nextLine();

        System.out.print(" - Estado da agência: ");
        String estado = sc.nextLine();

        System.out.print(" - Bairro da agência: ");
        String bairro = sc.nextLine();

        System.out.print(" - Gerente da agência: ");
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
        LocalDate dataNascimento = lerData();

        return new Cliente(cpf, nome, endereco, estadoCivil, escolaridade, dataNascimento);
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

        System.out.print(" - Salário (inteiro): ");
        double salario = sc.nextDouble();

        System.out.print(" - Número da carteira (inteiro): ");
        int carteira = sc.nextInt();

        System.out.println(" - Data de nascimento:");
        LocalDate dataNascimento = lerData();

        System.out.println(" - Data de ingresso na empresa:");
        LocalDate dataI = lerData();

        return new Funcionario(cpf, nome, endereco, estadoCivil, dataNascimento, carteira, rg, sexo, cargo, salario, dataI);
    }

    public static Gerente cadastrarGerente() {
        Scanner sc = new Scanner(System.in);
        Funcionario fTemp = cadastrarFuncionario();

        System.out.println(" - Data de ingresso na gerencia:");
        LocalDate dataIG = lerData();

        System.out.print(" - Possui curso de gerência? (sim ou não)\n-> ");
        String resposta = sc.nextLine();
        boolean curso = resposta.compareToIgnoreCase("sim") == 0;

        return new Gerente(fTemp.getCPF(), fTemp.getNome(), fTemp.getEndereco(), fTemp.getEstadoCivil(), LocalDate.of(fTemp.getAnoNascimento(),
                fTemp.getMesNascimento(), fTemp.getDiaNascimento()), fTemp.getNumeroCarteira(), fTemp.getRg(), fTemp.getSexo(),
                fTemp.getCargo(), fTemp.getSalario(), LocalDate.of( fTemp.getAnoIngresso(), fTemp.getMesIngresso(), fTemp.getDiaIngresso()),
               dataIG, curso);
    }

    public static Conta criarConta(Cliente cliente, Cliente contaConjunta) {
        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("Deseja criar qual tipo de conta?");
            System.out.println(" - 1: Conta corrente.");
            System.out.println(" - 2: Conta poupança.");
            System.out.println(" - 3: Conta salário.");
            System.out.print("Tipo: ");
            int escolha = sc.nextInt();

            int agencia;
            Agencia[] agencias = inicializaAgencias(inicializaGerentes());
            System.out.println("\n-----\nEscolha a agência desejada:\n----");
            escolheAgencias(agencias);
            System.out.print("Agencia: ");
            agencia = sc.nextInt() - 1;

            System.out.print("Digite a senha da conta: ");
            int senha = sc.nextInt();

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
        System.out.print(" - Limite cheque especial: ");
        double limite = sc.nextDouble();
        System.out.print(" - Taxa administrativa: ");
        double taxaAdm = sc.nextDouble();

        return new ContaCorrente(senha, numeroConta(), 0, limite, taxaAdm, agencia, cliente, contaConjunta);
    }

    private static Conta criarContaPoupanca(Cliente cliente, Cliente contaConjunta, int senha, Agencia agencia) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Digite as características da conta poupança: ");
        System.out.print(" - Rendimento mensal: ");
        double rendimentoMes = sc.nextDouble();

        return new ContaPoupanca(senha, numeroConta(), 0, rendimentoMes, agencia, cliente, contaConjunta);
    }

    private static Conta criarContaSalario(Cliente cliente, Cliente contaConjunta, int senha, Agencia agencia) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Digite as características da conta corrente: ");
        System.out.print(" - Limite saque: ");
        double saque = sc.nextDouble();
        System.out.print(" - Limite transferencia: ");
        double transferencia = sc.nextDouble();

        return new ContaSalario(senha, numeroConta(), 0, saque, transferencia, agencia, cliente, contaConjunta);
    }

    public static Cliente escolherCliente() {
        Scanner sc = new Scanner(System.in);
        mostraClientes();

        ArrayList<Cliente> clientes = (ArrayList<Cliente>) Persist.recuperar("clientes.dat");
        assert clientes != null;
        if (clientes.size() == 0)
            return null;
        System.out.print("--------\nCliente desejado: ");
        int clienteIndex = sc.nextInt() - 1;

        return clientes.get(clienteIndex);
    }

    public static void limparDados() {
        DadosContas.limparContas();
        DadosClientes.limparClientes();
        DadosContas.inicializaContas();
        DadosClientes.inicializaClientes();
    }

    public static void mostraContas() {
        DadosContas.inicializaContas();
        ArrayList<Conta> contas = (ArrayList<Conta>) Persist.recuperar("contas.dat");
        if(contas == null) {
            System.out.println("Não existem clientes cadastrados!");
            return;
        }
        int contador = 1;
        for (Conta conta : contas) {
            System.out.println("-----------\nConta: " + contador++ + "\n----");
            try {
                conta.imprimeDados();
            } catch (RuntimeException e) {
                System.out.println(e.getMessage());
            }
        }
        if (contas.size() == 0)
            System.out.println("Não existem contas cadastradas!");
    }

    public static void mostraClientes() {
        ArrayList<Cliente> clientes = (ArrayList<Cliente>) Persist.recuperar("clientes.dat");
        if(clientes == null) {
            System.out.println("Não existem clientes cadastrados!");
            return;
        }
        int contador = 1;
        for (Cliente cliente : clientes) {
            System.out.println("-----------\nCliente: " + contador++ + "\n----");
            try {
                cliente.imprimeCliente();
            } catch (RuntimeException e) {
                System.out.println(e.getMessage());
            }
        }
        if (clientes.size() == 0)
            System.out.println("Não existem clientes cadastrados!");
    }

    public static void mostraFuncionarios(ArrayList<Funcionario> funcionarios) {
        for (Funcionario f : funcionarios) {
            System.out.println("------");
            f.imprimeDados();
        }
    }

    public static void mostraGerentes(ArrayList<Gerente> gerentes) {
        for (Gerente g : gerentes) {
            System.out.println("------");
            g.imprimeDados();
        }
    }


    private static LocalDate lerData() {
        Scanner sc = new Scanner(System.in);
        int diaIG,  mesIG, anoIG;
        while (true) {
            System.out.print(" --> Dia: ");
            diaIG = sc.nextInt();
            if (diaIG >= 1 && diaIG <= 31) {
                break;
            }
            System.out.println("Dia inválido! Digite o dia novamente!");
        }

        while (true) {
            System.out.print(" --> Mês: ");
            mesIG = sc.nextInt();
            if (mesIG >= 1 && mesIG <= 12) {
                break;
            }
            System.out.println("Mês inválido! Digite o més novamente!");
        }

        while (true) {
            System.out.print(" --> Ano: ");
            anoIG = sc.nextInt();
            if (anoIG >= 1900 && anoIG <= LocalDate.now().getYear()) {
                break;
            }
            System.out.println("Ano inválido! Digite o ano novamente!");
        }

        return LocalDate.of(anoIG, mesIG, diaIG);
    }

    public static void voltarAoMenu() {
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.print("\n - 1 para voltar ao menu: ");
            int voltar = sc.nextInt();
            if (voltar == 1)
                break;
        }
    }

    private static int numeroConta() {
        ArrayList<Conta> contas = (ArrayList<Conta>) Persist.recuperar("contas.dat");
        assert contas != null;
        Conta conta = contas.size() != 0 ? contas.get(contas.size() - 1) : null;
        return conta != null ? conta.getNumeroConta()+1 : 1240;
    }

    public static void dadosConta() {
        Scanner sc = new Scanner(System.in);

        ArrayList<Conta> contas = (ArrayList<Conta>) Persist.recuperar("contas.dat");
        assert contas != null;
        if (contas.size() == 0) {
            System.out.println("Não existem contas cadastradas!");
            return;
        }
        while (true) {
            System.out.print("Digite o número da conta: ");
            int numeroConta = sc.nextInt();
            Conta printar = null;
            int i;
            for (i = contas.size(); i > 0; i--) {
                if (contas.get(contas.size() - i).getNumeroConta() == numeroConta) {
                    printar = contas.get(contas.size() - i);
                    contas.remove(contas.size() - i);
                    break;
                }
            }
            if (printar != null) {
                System.out.println("--------");
                printar.imprimeDados();
                System.out.print("---\nDeseja ver os dados da última transação? (sim ou não)\n-> ");
                if (sc.hasNextLine())
                    sc.nextLine();
                String resposta = sc.nextLine();
                if (resposta.compareToIgnoreCase("sim") == 0) {
                    Transacao tmp = null;
                    while (true) {
                        System.out.print("Digite a senha da conta: ");
                        int senha = sc.nextInt();
                        try {
                            tmp = printar.getUltimaTransacao(senha);
                            break;
                        } catch (SenhaInvalidaException e) {
                            System.out.println(e.getMessage());
                        } catch (ContaInativaException | TransacoesVaziasException e) {
                            System.out.println(e.getMessage());
                            break;
                        }
                    }
                    if (tmp != null) tmp.imprimeTransacao();
                }
                System.out.println("--------");
                break;
            }
        }
    }

    public static void realizarTransacao() {
        Scanner sc = new Scanner(System.in);

        ArrayList<Conta> contas = (ArrayList<Conta>) Persist.recuperar("contas.dat");
        assert contas != null;
        Conta contaTransacao = null;
        if (contas.size() == 0) {
            System.out.println("Não existem contas cadastradas!");
            return;
        }
        while (true) {
            System.out.print("Digite o número da conta: ");
            int numeroConta = sc.nextInt();
            int i;
            for (i = contas.size(); i > 0; i--) {
                if (contas.get(contas.size() - i).getNumeroConta() == numeroConta) {
                    contaTransacao = contas.get(contas.size() - i);
                    contas.remove(contaTransacao);
                    break;
                }
            }
            if (contaTransacao != null)
                break;
            System.out.println("Conta não existe!");
        }

        System.out.println("Escolha a transação:");
        System.out.println(" - 1) Saque.");
        System.out.println(" - 2) Consultar saldo.");
        System.out.println(" - 3) Efetuar pagamento.");
        System.out.println(" - 4) Depósito.");
        System.out.print("Opção: ");
        int tipo = sc.nextInt();
        int senha;
        while (true) {
            System.out.print("Digite a senha da conta: ");
            senha = sc.nextInt();
            if (contaTransacao.autentica(senha))
                break;
            System.out.println("Senha inválida, digite novamente!");
        }
        switch (tipo) {
            case 1 -> {
                System.out.print("Valor a ser sacado: ");
                double valor = sc.nextDouble();
                if (sc.hasNextLine())
                    sc.nextLine();
                System.out.print("Canal: ");
                String canal = sc.nextLine();
                try {
                    contaTransacao.sacar(valor, senha, LocalDate.now(), canal);
                } catch (ContaInativaException | SenhaInvalidaException | SaldoInsuficienteExecption e) {
                    System.out.println(e.getMessage());
                }
            }
            case 2 -> {
                while (true) {
                    try {
                        System.out.println("Saldo da conta: " + contaTransacao.getSaldo(senha));
                        break;
                    } catch (SenhaInvalidaException e) {
                        System.out.println(e.getMessage());
                    } catch (ContaInativaException e) {
                        System.out.println(e.getMessage());
                        break;
                    }
                }
            }
            case 3 -> {
                System.out.print("Valor a ser sacado: ");
                double valor = sc.nextDouble();
                System.out.print("Canal: ");
                if (sc.hasNextLine())
                    sc.nextLine();
                String canal = sc.nextLine();
                System.out.println("Descrição do pagamento: ");
                String descricao = sc.nextLine();
                try {
                    contaTransacao.efetuarPagamento(valor, senha, LocalDate.now(), canal, descricao);
                } catch (ContaInativaException | SenhaInvalidaException | SaldoInsuficienteExecption e) {
                    System.out.println(e.getMessage());
                }
            }
            case 4 -> {
                System.out.print("Valor a ser depositado: ");
                double valor = sc.nextDouble();
                if (sc.hasNextLine())
                    sc.nextLine();
                System.out.print("Canal: ");
                String canal = sc.nextLine();
                try {
                    contaTransacao.depositar(valor, senha, LocalDate.now(), canal);
                } catch (ContaInativaException | SenhaInvalidaException | ValorInvalido e) {
                    System.out.println(e.getMessage());
                }
            }
        }

        contas.add(contaTransacao);
        DadosContas.limparContas();
        DadosContas.inicializaContas();
        for (Conta c : contas) {
            DadosContas.cadastrar(c);
        }
    }
    public static void desativarConta() {
        Scanner escolha = new Scanner(System.in);
        while (true) {
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
                while (true) {
                    System.out.print("Digite a senha da conta: ");
                    int senha = escolha.nextInt();
                    try {
                        desativada.encerrarConta(senha);
                        break;
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
                break;
            }
            System.out.println("Número da conta não existe! Digite outro");
        }
    }
}

