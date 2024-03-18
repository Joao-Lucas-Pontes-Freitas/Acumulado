import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public abstract class Conta implements AutenticaSenha {
    protected int senha;
    protected int numeroConta;
    protected double saldo;
    protected LocalDate dataAbertura;
    protected LocalDate dataUltimaMovimentacao;
    protected boolean contaAtiva;
    protected Agencia agencia;

    public Conta(int senha, int numeroConta, double saldo) {
        this.senha = senha;
        this.numeroConta = numeroConta;
        this.saldo = saldo;
        this.dataAbertura = LocalDate.now();
        this.dataUltimaMovimentacao = LocalDate.now();
        this.contaAtiva = true;
    }

    public int getNumeroConta() { return numeroConta; }
    public boolean getContaAtiva() { return contaAtiva; }

    public String getDataAbertura() {
        return dataAbertura.format(DateTimeFormatter.ofPattern("dd/MM/yyyy"));
    }
    public double getSaldo() { return saldo; }
    public String getDataUltimaMovimentacao() { return dataUltimaMovimentacao.format(DateTimeFormatter.ofPattern("dd/MM/yyyy")); }
    public Agencia getAgencia() { return agencia; }

    public void setAgencia(Agencia agencia) { this.agencia = agencia; }

    public void encerrarConta(int pwd) {
        if (autentica(pwd))
            contaAtiva = false;
        else
            throw new SenhaInvalida("Não foi possível alterar o estado da conta! Senha inválida!");
    }
    protected void setDataUltimaMovimentacao() {
        dataUltimaMovimentacao = LocalDate.now();
    }
    public boolean autentica(int senha) {
        return this.senha == senha;
    }
}
