import java.time.LocalDate;
public class Gerente extends Funcionario {
    private LocalDate dataIngressoGerencia;
    private Agencia agencia;
    private boolean possuiCursoGerencia;

    public Gerente(String cpf, String nome, String endereco, String estadoCivil, LocalDate dataNascimento,
                   int numeroCarteira, String rg, String sexo, String cargo, double salario, LocalDate dataIngresso, LocalDate dataIngresoGerencia,
                   Agencia agencia, boolean possuiCursoGerencia) {
        super(cpf, nome, endereco, estadoCivil, dataNascimento, numeroCarteira, rg, sexo, cargo, salario, dataIngresso);
        this.dataIngressoGerencia = dataIngresoGerencia;
        this.agencia = agencia;
        this.possuiCursoGerencia = possuiCursoGerencia;
    }

    public static double comissao(){ //arrumar comissão
        return 0.1;
    }
    public LocalDate getDataIngresso() {
        return dataIngressoGerencia;
    }
    public void setDataIngresso(LocalDate dataIngressoGerencia) {
        this.dataIngressoGerencia = dataIngressoGerencia;
    }
    public Agencia getAgencia() {
        return agencia;
    }
    public void setAgencia(Agencia agencia) {
        this.agencia = agencia;
    }
    public boolean isPossuiCursoGerencia() {
        return possuiCursoGerencia;
    }
    public void setPossuiCursoGerencia(boolean possuiCursoGerencia) {
        this.possuiCursoGerencia = possuiCursoGerencia;
    }

    public void calcularSalario(){
        super.calcularSalario(salario);
        salario += comissao(); //arrumar comissão
    }
}
