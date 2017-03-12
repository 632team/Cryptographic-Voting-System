package dao.model;

public class Candidate {
	private int id;
	private String name;
	private int age;
	private String sex;
	private String ic;
	private String record;
	private String delcaration;
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getSex() {
		return sex;
	}
	public void setSex(String sex) {
		this.sex = sex;
	}
	public String getIc() {
		return ic;
	}
	public void setIc(String ic) {
		this.ic = ic;
	}
	public String getRecord() {
		return record;
	}
	public void setRecord(String record) {
		this.record = record;
	}
	public String getDelcaration() {
		return delcaration;
	}
	public void setDelcaration(String delcaration) {
		this.delcaration = delcaration;
	}
}
