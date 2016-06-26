package;

/**
 * ...
 * @author DustMan
 */
class GreyGuyCrouchAction extends ActorAction
{

	public function new(greyGuy:GreyGuyActor, beatOffset:Int=0) 
	{
		super(greyGuy, beatOffset);
	}

	override public function doAction():Void
	{
		// Actual animation frame count: ???
		trace("down");
		actor.playAnimationByName("crouch");
	}
}