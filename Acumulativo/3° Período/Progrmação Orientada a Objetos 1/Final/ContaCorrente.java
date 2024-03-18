import java.io.Serializable;

public class ContaCorrente extends Conta implements Serializable {
    private double limiteChequeEspecial;
    private double taxaAdministrativa;

    public ContaCorrente(int senha, int numeroConta, double saldo, double limiteChequeEspecial, double taxaAdministrativa, Agencia agencia, Cliente cliente, Cliente contaConjunta) {
        super(senha, numeroConta, saldo, agencia, cliente, contaConjunta);
        this.limiteChequeEspecial = limiteChequeEspecial;
        this.taxaAdministrativa = taxaAdministrativa;
    }

    public void setLimiteChequeEspecial(double limiteChequeEspecial) { this.limiteChequeEspecial = limiteChequeEspecial; }
    public void setTaxaAdministrativa(double taxaAdministrativa) { this.taxaAdministrativa = taxaAdministrativa; }

    public double getLimiteChequeEspecial() { return limiteChequeEspecial; }
    public double getTaxaAdministrativa() { return taxaAdministrativa; }

    public void imprimeDados(){
        imprimeConta();
        System.out.println("Limite Cheque Especial: " + limiteChequeEspecial);
        System.out.println("Taxa Administrativa: " + taxaAdministrativa);
    }
}
