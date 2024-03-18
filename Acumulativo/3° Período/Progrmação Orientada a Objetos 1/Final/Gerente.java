import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Gerente extends Funcionario{
    private LocalDate dataIngressoGerencia;
    private boolean possuiCursoGerencia;
    private static double comissao = 1000;

    public Gerente(String cpf, String nome, String endereco, String estadoCivil, LocalDate dataNascimento,
                   int numeroCarteira, String rg, String sexo, String cargo, double salario, LocalDate dataIngresso,
                   LocalDate dataIngresoGerencia, boolean possuiCursoGerencia) {
        super(cpf, nome, endereco, estadoCivil, dataNascimento, numeroCarteira, rg, sexo, cargo, salario, dataIngresso);
        if(dataIngresoGerencia == null)
            throw new DataNulaExecption("Data não pode ser nula");
        this.dataIngressoGerencia = dataIngresoGerencia;
        this.possuiCursoGerencia = possuiCursoGerencia;
        this.salario = salario;
    }

    public Gerente() {
        super();
    }

    public String getDataIngressoGerencia() { return dataIngressoGerencia.format(DateTimeFormatter.ofPattern("dd/MM/yyyy")); }
    public int getDiaIngressoGerencia() { return dataIngressoGerencia.getDayOfMonth(); }
    public int getMesIngressoGerencia() { return dataIngressoGerencia.getMonthValue(); }
    public int getAnoIngressoGerencia() { return dataIngressoGerencia.getYear(); }
    public static double getComissao() { return comissao; }

    public void setDataIngressoGerencia(LocalDate dataIngressoGerencia) { this.dataIngressoGerencia = dataIngressoGerencia; }
    public void setPossuiCursoGerencia(boolean possuiCursoGerencia) { this.possuiCursoGerencia = possuiCursoGerencia; }
    public static void setComissao(double novaComissao) { comissao = novaComissao; }

    public boolean isPossuiCursoGerencia() { return possuiCursoGerencia; }

    public void calcularSalario(double salario) {
        super.calcularSalario(salario);
        this.salario += comissao;
    }

    public void imprimeDados() {
        super.imprimeDados();
        System.out.println("Data de ingresso na gerência: " + getDataIngressoGerencia());
        System.out.println("Possui curso de gerencia: " + (possuiCursoGerencia ? "Sim" : "Não"));
    }
}
