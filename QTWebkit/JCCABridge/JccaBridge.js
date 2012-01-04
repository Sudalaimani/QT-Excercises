var gm = new Object();

gm.getName = GetName;

function GetName(Success,Failure,EmpDetails)
{
	var objName = GMInternal.getNameObject();
	GMInternal[objName].Success.connect(Success);
	GMInternal[objName].Failure.connect(Failure);
	GMInternal[objName].getName(EmpDetails);

}
