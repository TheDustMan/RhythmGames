package;

/**
 * ...
 * @author DustMan
 */
class GreyGuyStandAction extends ActorAction
{

	public function new(greyGuy:GreyGuyActor, beatOffset:Int=0) 
	{
		super(greyGuy, beatOffset);
	}

	override public function doAction():Void
	{
		// Actual animation frame count: ???
		trace("stand");
		actor.playAnimationByName("stand");
	}
}