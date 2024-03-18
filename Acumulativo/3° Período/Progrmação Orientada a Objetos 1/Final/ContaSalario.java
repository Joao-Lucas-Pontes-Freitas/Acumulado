public class ContaSalario extends Conta {
    protected double limiteSaque;
    protected double limiteTransferencia;

    public ContaSalario(int senha, int numeroConta, double saldo, double limiteSaque, double limiteTransferencia, Agencia agencia, Cliente cliente, Cliente contaConjunta) {
        super(senha, numeroConta, saldo, agencia, cliente, contaConjunta);
        this.limiteSaque = limiteSaque;
        this.limiteTransferencia = limiteTransferencia;
    }

    public void setLimiteSaque(double limiteSaque) { this.limiteSaque = limiteSaque; }
    public void setLimiteTransferencia(double limiteTransferencia) { this.limiteTransferencia = limiteTransferencia; }

    public double getLimiteSaque() { return limiteSaque; }
    public double getLimiteTransferencia() { return limiteTransferencia; }
    public void imprimeDados(){
        imprimeConta();
        System.out.println("Limite Saque: " + getLimiteSaque());
        System.out.println("Limite Transferencia: " + getLimiteTransferencia());
    }
}
