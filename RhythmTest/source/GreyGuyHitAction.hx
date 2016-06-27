package;

/**
 * ...
 * @author DustMan
 */
class GreyGuyHitAction extends ActorAction
{

	public function new(greyGuy:GreyGuyActor, beatOffset:Int=0) 
	{
		super(greyGuy, beatOffset);
	}

	override public function doAction():Void
	{
		// Actual animation frame count: ???
		trace("hit");
		actor.playAnimationByName("hit");
	}
}