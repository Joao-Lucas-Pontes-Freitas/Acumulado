import java.time.LocalDate;

public class Funcionario extends Pessoa {
    protected int numeroCarteira;
    protected String rg;
    protected String sexo;
    protected String cargo;
    protected double salario;
    private LocalDate dataIngresso;

    public Funcionario(String cpf, String nome, String endereco, String estadoCivil, LocalDate dataNascimento,
                       int numeroCarteira, String rg, String sexo, String cargo, double salario, LocalDate dataIngresso) {
        super(cpf, nome, endereco, estadoCivil, dataNascimento);
        this.numeroCarteira = numeroCarteira;
        this.rg = rg;
        this.sexo = sexo;
        this.cargo = cargo;
        this.dataIngresso = dataIngresso;
        calcularSalario(salario);
    }
    public int getNumeroCarteira() { return numeroCarteira; }
    public String getRg() { return rg; }
    public String getSexo() { return sexo; }
    public String getCargo() { return cargo; }
    public double getSalario() { return salario; }
    public LocalDate getDataIngresso() { return dataIngresso; }

    public void setRg(String rg) { this.rg = rg; }
    public void setNumeroCarteira(int numeroCarteira) { this.numeroCarteira = numeroCarteira; }
    public void setDataIngresso(LocalDate dataIngresso) { this.dataIngresso = dataIngresso; }
    public void setSexo(String sexo) { this.sexo = sexo; }
    public void setCargo(String cargo) { this.cargo = cargo; }

    public void calcularSalario(double salario){
        LocalDate compareDate = dataIngresso.plusYears(15);
        if (LocalDate.now().isAfter(compareDate))
            this.salario = salario * 1.1;
        else
            this.salario = salario;
    }
}
