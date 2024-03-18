import java.io.Serializable;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

public abstract class Conta implements AutenticaSenha, Serializable {
    protected int senha;
    protected int numeroConta;
    protected double saldo;
    protected LocalDate dataAbertura;
    protected LocalDate dataUltimaMovimentacao;
    protected boolean contaAtiva;
    protected Agencia agencia;
    protected ArrayList<Transacao> transacoes = new ArrayList<>();
    private Cliente[] clientes = new Cliente[2];

    public Conta(int senha, int numeroConta, double saldo, Agencia agencia, Cliente cliente, Cliente contaConjunta) {
        if(agencia == null)
            throw new AgenciaNulaException("Agência não pode ser nula");
        this.agencia = agencia;
        this.senha = senha;
        this.numeroConta = numeroConta;
        this.saldo = saldo;
        this.dataAbertura = LocalDate.now();
        this.dataUltimaMovimentacao = null;
        this.contaAtiva = true;
        this.clientes[0] = cliente;
        if (contaConjunta != null)
            this.clientes[1] = contaConjunta;
    }
    public int getNumeroConta() { return numeroConta; }
    public boolean getContaAtiva() { return contaAtiva; }
    public String getDataAbertura() {
        return dataAbertura.format(DateTimeFormatter.ofPattern("dd/MM/yyyy"));
    }

    public double getSaldo(int senha) {
        if(!autentica(senha))
            throw new SenhaInvalidaException("Senha inválida!");
        return saldo;
    }

    public String getDataUltimaMovimentacao() { return dataUltimaMovimentacao.format(DateTimeFormatter.ofPattern("dd/MM/yyyy")); }
    public Agencia getAgencia() { return agencia; }

    public void setAgencia(Agencia agencia) { this.agencia = agencia; }

    public void encerrarConta(int pwd) {
        if (autentica(pwd))
            contaAtiva = false;
        else
            throw new SenhaInvalidaException("Não foi possível alterar o estado da conta! Senha inválida!");
    }
    protected void setDataUltimaMovimentacao() {
        dataUltimaMovimentacao = LocalDate.now();
    }
    public boolean autentica(int senha) {
        return this.senha == senha;
    }
    public boolean maiorQue(Classificavel o){
        Conta compara = (Conta) o;
        return numeroConta > compara.numeroConta;
    }
    public void sacar(double valor, int senha, LocalDate data, String canal) {
        if(!contaAtiva)
            throw new ContaInativaException("Conta inativa!");
        if(!autentica(senha))
            throw new SenhaInvalidaException("Senha inválida!");
        if (valor > saldo)
            throw new SaldoInsuficienteExecption("Saldo insuficiente!");
        saldo -= valor;
        setDataUltimaMovimentacao();
        Transacao t = new Transacao(data, valor, canal);
        transacoes.add(t);
    }
    public void efetuarPagamento(double valor, int senha, LocalDate data, String canal, String tipo) {
        if(!contaAtiva)
            throw new ContaInativaException("Conta inativa!");
        if(!autentica(senha))
            throw new SenhaInvalidaException("Senha inválida!");
        if (valor > saldo)
            throw new SaldoInsuficienteExecption("Saldo insuficiente!");
        saldo -= valor;
        setDataUltimaMovimentacao();
        Transacao t = new Transacao(data, valor, canal);
        transacoes.add(t);
    }
    public void depositar(double valor, int senha, LocalDate data, String canal) {
        if(!contaAtiva)
            throw new ContaInativaException("Conta inativa!");
        if(!autentica(senha))
            throw new SenhaInvalidaException("Senha inválida!");
        if (valor <= 0.0)
            throw new ValorInvalido("Valor inválido!");
        saldo += valor;
        setDataUltimaMovimentacao();
        Transacao t = new Transacao(data, valor, canal);
        transacoes.add(t);
    }
    public Transacao getUltimaTransacao(int senha) {
        if(!contaAtiva)
            throw new ContaInativaException("Conta inativa!");
        if(!autentica(senha))
            throw new SenhaInvalidaException("Senha inválida!");
        if (transacoes.isEmpty()) {
            throw new RuntimeException("Não há transações nesta conta!");
        }
        return transacoes.get(transacoes.size()-1);
    }
    public void imprimeConta() {
        System.out.println("Numero da conta: " + numeroConta);
        System.out.println("Saldo: " + saldo);
        System.out.println("Data de abertura: " + getDataAbertura());
        System.out.println("Data da ultima movimentacao: " + getDataUltimaMovimentacao());
        System.out.println("Conta ativa: " + contaAtiva);
        System.out.println("Agencia: " + agencia.getNomeFicticio());
    }
    public abstract void imprimeDados(); //Método abstrato para mostrar todos os dados da conta, precisa ser abastrato
    // pois cada tipo de conta contém atriubutos diferentes, logo cada um tem uma implementação diferente.
}
