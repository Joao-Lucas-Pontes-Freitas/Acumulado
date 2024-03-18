public class ContaPoupanca extends Conta {
    private double rendimentoMes;

    public ContaPoupanca(int senha, int numeroConta, double saldo, double rendimentoMes) {
        super(senha, numeroConta, saldo);
        this.rendimentoMes = rendimentoMes;
    }

    void setRendimentoMes(double rendimentoMes) { this.rendimentoMes = rendimentoMes; }

    double getRendimentoMes() { return rendimentoMes; }
}