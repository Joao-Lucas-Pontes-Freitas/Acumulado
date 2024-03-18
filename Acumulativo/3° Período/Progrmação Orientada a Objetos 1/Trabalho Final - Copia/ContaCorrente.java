public class ContaCorrente extends Conta {
    private double limiteChequeEspecial;
    private double taxaAdministrativa;

    public ContaCorrente(int senha, int numeroConta, double saldo, double limiteChequeEspecial, double taxaAdministrativa) {
        super(senha, numeroConta, saldo);
        this.limiteChequeEspecial = limiteChequeEspecial;
        this.taxaAdministrativa = taxaAdministrativa;
    }

    public void setLimiteChequeEspecial(double limiteChequeEspecial) { this.limiteChequeEspecial = limiteChequeEspecial; }
    public void setTaxaAdministrativa(double taxaAdministrativa) { this.taxaAdministrativa = taxaAdministrativa; }

    public double getLimiteChequeEspecial() { return limiteChequeEspecial; }
    public double getTaxaAdministrativa() { return taxaAdministrativa; }
}
