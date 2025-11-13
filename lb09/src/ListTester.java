// -------------------------------------------------------------------
// ListTester.java 
// -------------------------------------------------------------------

import lb09.lib.List ;


/**
 * This class  implements a simple  program to test a  generic, simply
 * connected linked list.
 *
 * @author Marcelo Ferreira Siqueira
 * @author <a href="mailto:mfsiqueira@dimap.ufrn.br">mfsiqueira@dimap.ufrn.br</a>
 * @author <a target="_blank" href="http://www.dimap.ufrn.br/~mfsiqueira">www.dimap.ufrn.br/~mfsiqueira</a>
 * @version 1.0,  &nbsp; 2009-MAY-11
 * @since JDK1.5
 *
 */

public class ListTester
{

    public static void main( String[] args )
    {
	List< Integer , String > mylist = new List< Integer , String>() ;

	try
	{
	    mylist.insert( new Integer( 10 ) , new String( "dez" ) ) ;
	    mylist.insert( new Integer( 20 ) , new String( "vinte" ) ) ;
	    mylist.insert( new Integer(  4 ) , new String( "quatro" ) ) ;
	    mylist.insert( new Integer( 13 ) , new String( "treze" ) ) ;
	    
	    if ( mylist.getValue( new Integer( 5 ) ) != null )
	    {
		mylist.remove( new Integer( 5 ) ) ;
	    }

	    mylist.remove( new Integer( 4 ) ) ;

	    if ( mylist.isEmpty() )
	    {
		return ;
	    }

	    mylist.remove( new Integer( 13 ) ) ;
	    mylist.remove( new Integer( 10 ) ) ;
	    mylist.remove( new Integer( 20 ) ) ;

	    if ( mylist.isEmpty() )
	    {
		System.out.println( "List is empty! ") ;
	    }
	    
	    mylist.insert( new Integer( 6 ) , new String( "seis" ) ) ;

	    System.out.printf( "%s\n" , mylist.getValue( new Integer( 6 ) ) ) ;

	    mylist.remove( new Integer( 6 ) ) ;

	    mylist.remove( new Integer( 7 ) ) ;
	}
	catch ( Exception exception )
	{
	    exception.printStackTrace( ) ;
	}

	return ;
    }
}


