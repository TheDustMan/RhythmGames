package;

/**
 * @author DustMan
 */
interface IPlayerState 
{
	public function onStateEnter():void;
	public function frameHook():void;

	public function a_down():void;
	public function b_down():void;
	public function x_down():void;
	public function y_down():void;
	public function rt_down():void;
	public function lt_down():void;
	
	public function a_up():void;
	public function b_up():void;
	public function x_up():void;
	public function y_up():void;
	public function rt_up():void;
	public function lt_up():void;
	

}