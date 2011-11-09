class Path{
	private String type;
	private int idfrom, idto;
	private boolean used, NTSave;
	
	public Path(){
		used = false;
	}
	
	public Path(String typeIn, int idfromIn, int idtoIn){
		type = typeIn;
		idfrom = idfromIn;
		idto = idtoIn;
		used = true;
	}
	
	public void setType(String typeIn){
		type = typeIn;
	}
	
	public void setIdto(int idtoIn){
		idto = idtoIn;
	}
	
	public void setIdfrom(int idfromIn){
		idfrom = idfromIn;
	}
	
	
	
	public String getType(){
		return type;
	}
	
	public int getIdfrom(){
		return idfrom;
	}
	
	public int getIdto(){
		return idto;
	}
	
	public void setUsed(boolean setTo){
		used = setTo;
	}
	
	public boolean getUsed(){
		return used;
	}
	
	public void setNTSave(boolean in){
		NTSave = in;
	}
	
	public boolean getNTSave(){
		return NTSave;
	}
}

