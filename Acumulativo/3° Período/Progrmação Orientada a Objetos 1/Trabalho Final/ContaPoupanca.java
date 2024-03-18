public class ContaPoupanca extends Conta {
    private double rendimentoMes;

    public ContaPoupanca(int senha, int numeroConta, double saldo, double rendimentoMes, Agencia agencia, Cliente cliente, Cliente contaConjunta) {
        super(senha, numeroConta, saldo, agencia, cliente, contaConjunta);
        this.rendimentoMes = rendimentoMes;
    }

    void setRendimentoMes(double rendimentoMes) { this.rendimentoMes = rendimentoMes; }

    double getRendimentoMes() { return rendimentoMes; }

    public void imprimeDados(){
        imprimeConta();
        System.out.println("Rendimento: " + rendimentoMes);
    }
}